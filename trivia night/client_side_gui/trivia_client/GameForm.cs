using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Timer = System.Windows.Forms.Timer;
using System.Threading;

namespace trivia_client
{
    public partial class GameForm : Form
    {
        private ServerCommunicator _communicator;
        private Timer GeneralTimer;
        private int startingCountDown;
        private int EndGameCounter = 0;
        private int timeMaxCountDown;
        private bool waitReached = false;
        public GameForm(ServerCommunicator communicator, int startingCountDown, int timeMaxCountDown)
        {
            InitializeComponent();
            _communicator = communicator;
            this.startingCountDown = startingCountDown;
            this.timeMaxCountDown = timeMaxCountDown * 100; // so the up wont be robotic
            this.timerBar.Maximum = timeMaxCountDown * 100; // max size of value bar
        }

        public GameForm(int startingCountDown, int timeMaxCountDown)
        {
            InitializeComponent();
            this.startingCountDown = startingCountDown;
            this.timeMaxCountDown = timeMaxCountDown * 100; // so the up wont be robotic
            this.timerBar.Maximum = timeMaxCountDown * 100; // max size of value bar
        }

        private void CountDownInitiation(object sender, EventArgs e)
        {
            if (this.startingCountDown == 0)
            {
                this.GameCountDownTimer.Location = new Point(this.GameCountDownTimer.Location.X - 70, this.GameCountDownTimer.Location.Y);
                this.GameCountDownTimer.Text = "Start!";
                this.GameCountDownTimer.ForeColor = Color.Gold;

                this.startingCountDown--;
                return;
            }
            else if (this.startingCountDown < 0)
            {
                // show the game button questions and timer
                this.GameCountDownTimer.Hide();
                this.GameCountDownTextSaver.Hide();
                this.questionHolder.Show();
                this.GeneralTimer.Stop();
                this.timerBar.Show();
                this.timeShowText.Show();
                this.label1.Show();
                this.aHolder1.Show();
                this.aHolder2.Show();
                this.aHolder3.Show();
                this.aHolder4.Show();
                this.updateDisplayQuestion(sender, e);
                this.GeneralTimer.Interval = 10;
                this.GeneralTimer.Tick -= new EventHandler(CountDownInitiation);
                this.GeneralTimer.Tick += new EventHandler(update_timeBar);
                this.GeneralTimer.Start();
                return;
            }
            else
            {
                this.GameCountDownTimer.Text = this.startingCountDown.ToString();
                this.startingCountDown--;
                return;
            }
        }

        private void GameForm_Load(object sender, EventArgs e)
        {
            this.CountDownInitiation(sender, e);
            this.GeneralTimer = new Timer();
            this.GeneralTimer.Interval = 1000;
            this.GeneralTimer.Start();
            this.GeneralTimer.Tick += new EventHandler(CountDownInitiation);
        }

        private void updateDisplayQuestion(object sender, EventArgs e)
        {
            this.GeneralTimer.Stop();
            this._communicator.sendMsg(Serializer.serializeGetQuestion());
            string serverMsg = this._communicator.recvMsg();

            if (deserializer.getMSGcode(serverMsg) == ((int)codeTypes.ERROR_CODE))
            {
                var frm = new ShowErrorForm(deserializer.deserializeErrorResp(serverMsg).message);
                frm.Location = this.Location;
                frm.StartPosition = FormStartPosition.CenterScreen;
                frm.FormClosing += delegate { this.Show(); };
                this.Hide();
                frm.ShowDialog();
            }
            else
            {
                GetQuestionRespHolder resp = deserializer.deserializeGetQuestionResponse(serverMsg);
                switch (resp.status)
                {
                    case 0: // if all users finish open the game end results
                        {
                            this.GeneralTimer.Stop();
                            var frm = new EndGameForm(this._communicator);
                            frm.Location = this.Location;
                            frm.StartPosition = FormStartPosition.CenterScreen;
                            frm.FormClosing += delegate { this.Show(); };
                            this.Hide();
                            frm.ShowDialog();
                            this.Close();
                            break;
                        }

                    case 1: // get next question
                        {
                            this.questionHolder.Text = resp.question;
                            //
                            string[] answers = resp.answers.Split("@#@#@");
                            this.aHolder1.Text = answers[0];
                            this.aHolder2.Text = answers[1];
                            this.aHolder3.Text = answers[2];
                            this.aHolder4.Text = answers[3];
                            this.timerBar.Value = 0;
                            this.update_timeBar(sender, e);
                            this.GeneralTimer.Start();
                            break;
                        }

                    case 2: // wait until all users finish the questions
                        {
                            if (!waitReached)
                            {
                                this.GeneralTimer.Interval = 1000;
                                this.GeneralTimer.Tick -= new EventHandler(update_timeBar);
                                this.GeneralTimer.Tick += new EventHandler(updateDisplayQuestion);
                                this.waitReached = true;
                            }
                            this.updateEndGameWait(sender, e);
                            this.GeneralTimer.Start();
                            break;
                        }

                    default:
                        {

                            this.GeneralTimer.Start();
                            break;
                        }
                }

            }
        }

        private void updateEndGameWait(object sender, EventArgs e)
        {
            if (this.EndGameCounter == 0) // waiting animation
            {
                this.aHolder1.Hide();
                this.aHolder2.Hide();
                this.aHolder3.Hide();
                this.aHolder4.Hide();
                this.questionHolder.Hide();
                this.timerBar.Hide();
                this.timeShowText.Hide();
                this.label1.Hide();
                this.waitToggleHolder.Show();
                this.WaitTextHolder.Show();

                this.WaitTextHolder.Text = "Please wait until all players finish the game...";
                this.WaitTextHolder.Text = "( ͡° ͜ʖ ͡°)";
                this.EndGameCounter++;
            }
            else if (this.EndGameCounter == 1)
            {
                this.waitToggleHolder.Text = "(づ｡◕‿‿◕｡)づ";
                this.EndGameCounter++;
            }
            else if (this.EndGameCounter == 2)
            {
                this.waitToggleHolder.Text = "┬┴┬┴┤ ͜ʖ ͡°) ├┬┴┬┴";
                this.EndGameCounter++;
            }
            else if (this.EndGameCounter == 3)
            {
                this.waitToggleHolder.Text = "(｡◕‿‿◕｡)";
                this.EndGameCounter = 0;
            }
        }

        private async void roundedButton4_Click(object sender, EventArgs e)
        {
            this.GeneralTimer.Stop();
            string result = submitAnswer(this.aHolder4.Text, sender, e);
            if (aHolder4.Text == result)
            {
                this.aHolder4.BackColor = Color.ForestGreen;
                this.aHolder4.ForeColor = Color.WhiteSmoke;
                await Task.Delay(1500);
                this.updateDisplayQuestion(sender, e);
                this.aHolder4.BackColor = Color.WhiteSmoke;
                this.aHolder4.ForeColor = Color.Red;
            }
            else
            {
                this.aHolder4.BackColor = Color.Red;
                this.aHolder4.ForeColor = Color.WhiteSmoke;
                if (this.aHolder1.Text == result)
                {
                    this.aHolder1.BackColor = Color.ForestGreen;
                    this.aHolder1.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder1.BackColor = Color.WhiteSmoke;
                    this.aHolder1.ForeColor = Color.Red;
                }
                else if (this.aHolder2.Text == result)
                {
                    this.aHolder2.BackColor = Color.ForestGreen;
                    this.aHolder2.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder2.BackColor = Color.WhiteSmoke;
                    this.aHolder2.ForeColor = Color.Red;
                }
                else if (this.aHolder3.Text == result)
                {
                    this.aHolder3.BackColor = Color.ForestGreen;
                    this.aHolder3.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder3.BackColor = Color.WhiteSmoke;
                    this.aHolder3.ForeColor = Color.Red;
                }
                this.updateDisplayQuestion(sender, e);
                this.aHolder4.BackColor = Color.WhiteSmoke;
                this.aHolder4.ForeColor = Color.Red;
            }


            // do not need to start again because the question getter does that
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void update_timeBar(object sender, EventArgs e)
        {
            if (this.timeMaxCountDown == this.timerBar.Value)
            {
                this.submitAnswer("", sender, e);
                this.timerBar.Value = 0;
                this.updateDisplayQuestion(sender, e);
            }
            else
            {
                this.timerBar.Value++;
            }
            int minute = 0, second = 0;
            int tmp = (this.timeMaxCountDown / 100) - (this.timerBar.Value / 100);
            minute = tmp / 60;
            second = tmp % 60;
            string disp = "";
            if (minute < 10)
            {
                disp = "0" + minute.ToString();
            }
            else
            {
                disp = minute.ToString();
            }
            disp += ":";
            if (second < 10)
            {
                disp += "0" + second.ToString();
            }
            else
            {
                disp += second.ToString();
            }

            this.timeShowText.Text = disp;
        }

        // need to stop timer before call.
        private string submitAnswer(string answer, object sender, EventArgs e)
        {
            // sends a answer submition request
            this._communicator.sendMsg(Serializer.serializeSubmitAnswer(answer, (this.timerBar.Value / 100)));
            string serverMsg = this._communicator.recvMsg();


            if (deserializer.getMSGcode(serverMsg) == ((int)codeTypes.ERROR_CODE))
            {
                var frm = new ShowErrorForm(deserializer.deserializeErrorResp(serverMsg).message);
                frm.Location = this.Location;
                frm.StartPosition = FormStartPosition.CenterScreen;
                frm.FormClosing += delegate { this.Show(); };
                this.Hide();
                frm.ShowDialog();
                return "Error";
            }
            else
            {
                SubmitAnswerRespHolder resp = deserializer.deserializeSubmitAnswerResponse(serverMsg);
                return resp.correctAns;
            }
        }

        private async void aHolder3_Click(object sender, EventArgs e)
        {
            this.GeneralTimer.Stop();
            string result = submitAnswer(this.aHolder3.Text, sender, e);
            if (aHolder3.Text == result)
            {
                this.aHolder3.BackColor = Color.ForestGreen;
                this.aHolder3.ForeColor = Color.WhiteSmoke;
                await Task.Delay(1500);
                this.updateDisplayQuestion(sender, e);
                this.aHolder3.BackColor = Color.WhiteSmoke;
                this.aHolder3.ForeColor = Color.Red;
            }
            else
            {
                this.aHolder3.BackColor = Color.Red;
                this.aHolder3.ForeColor = Color.WhiteSmoke;
                if (this.aHolder1.Text == result)
                {
                    this.aHolder1.BackColor = Color.ForestGreen;
                    this.aHolder1.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder1.BackColor = Color.WhiteSmoke;
                    this.aHolder1.ForeColor = Color.Red;
                }
                else if (this.aHolder2.Text == result)
                {
                    this.aHolder2.BackColor = Color.ForestGreen;
                    this.aHolder2.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder2.BackColor = Color.WhiteSmoke;
                    this.aHolder2.ForeColor = Color.Red;
                }
                else if (this.aHolder4.Text == result)
                {
                    this.aHolder4.BackColor = Color.ForestGreen;
                    this.aHolder4.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder4.BackColor = Color.WhiteSmoke;
                    this.aHolder4.ForeColor = Color.Red;
                }
                this.updateDisplayQuestion(sender, e);
                this.aHolder3.BackColor = Color.WhiteSmoke;
                this.aHolder3.ForeColor = Color.Red;
            }


            // do not need to start again because the question getter does that
        }

        private async void aHolder1_Click(object sender, EventArgs e)
        {
            this.GeneralTimer.Stop();
            string result = submitAnswer(this.aHolder1.Text, sender, e);
            if (aHolder1.Text == result)
            {
                this.aHolder1.BackColor = Color.ForestGreen;
                this.aHolder1.ForeColor = Color.WhiteSmoke;
                await Task.Delay(1500);
                this.updateDisplayQuestion(sender, e);
                this.aHolder1.BackColor = Color.WhiteSmoke;
                this.aHolder1.ForeColor = Color.Red;
            }
            else
            {
                this.aHolder1.BackColor = Color.Red;
                this.aHolder1.ForeColor = Color.WhiteSmoke;
                if (this.aHolder3.Text == result)
                {
                    this.aHolder3.BackColor = Color.ForestGreen;
                    this.aHolder3.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder3.BackColor = Color.WhiteSmoke;
                    this.aHolder3.ForeColor = Color.Red;
                }
                else if (this.aHolder2.Text == result)
                {
                    this.aHolder2.BackColor = Color.ForestGreen;
                    this.aHolder2.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder2.BackColor = Color.WhiteSmoke;
                    this.aHolder2.ForeColor = Color.Red;
                }
                else if (this.aHolder4.Text == result)
                {
                    this.aHolder4.BackColor = Color.ForestGreen;
                    this.aHolder4.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder4.BackColor = Color.WhiteSmoke;
                    this.aHolder4.ForeColor = Color.Red;
                }
                this.updateDisplayQuestion(sender, e);
                this.aHolder1.BackColor = Color.WhiteSmoke;
                this.aHolder1.ForeColor = Color.Red;
            }


            // do not need to start again because the question getter does that
        }

        private async void aHolder2_Click(object sender, EventArgs e)
        {
            this.GeneralTimer.Stop();
            string result = submitAnswer(this.aHolder2.Text, sender, e);
            if (aHolder2.Text == result)
            {
                this.aHolder2.BackColor = Color.ForestGreen;
                this.aHolder2.ForeColor = Color.WhiteSmoke;
                await Task.Delay(1500);
                this.updateDisplayQuestion(sender, e);
                this.aHolder2.BackColor = Color.WhiteSmoke;
                this.aHolder2.ForeColor = Color.Red;
            }
            else
            {
                this.aHolder2.BackColor = Color.Red;
                this.aHolder2.ForeColor = Color.WhiteSmoke;
                if (this.aHolder1.Text == result)
                {
                    this.aHolder1.BackColor = Color.ForestGreen;
                    this.aHolder1.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder1.BackColor = Color.WhiteSmoke;
                    this.aHolder1.ForeColor = Color.Red;
                }
                else if (this.aHolder3.Text == result)
                {
                    this.aHolder3.BackColor = Color.ForestGreen;
                    this.aHolder3.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder3.BackColor = Color.WhiteSmoke;
                    this.aHolder3.ForeColor = Color.Red;
                }
                else if (this.aHolder4.Text == result)
                {
                    this.aHolder4.BackColor = Color.ForestGreen;
                    this.aHolder4.ForeColor = Color.WhiteSmoke;
                    await Task.Delay(1500);
                    this.aHolder4.BackColor = Color.WhiteSmoke;
                    this.aHolder4.ForeColor = Color.Red;
                }
                this.updateDisplayQuestion(sender, e);
                this.aHolder2.BackColor = Color.WhiteSmoke;
                this.aHolder2.ForeColor = Color.Red;
            }


            // do not need to start again because the question getter does that
        }

    }
}
