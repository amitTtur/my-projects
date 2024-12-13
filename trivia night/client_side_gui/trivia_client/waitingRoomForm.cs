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

namespace trivia_client
{
    public partial class waitingRoomForm : Form
    {
        private ServerCommunicator _communicator;
        private string _roomName;
        private int _timePerQuestion = 99;
        Timer Clock;
        public waitingRoomForm(ServerCommunicator communicator, string roomName)
        {
            InitializeComponent();
            _communicator = communicator;
            _roomName = roomName;
            this.FormClosed += new FormClosedEventHandler(exitRoom);
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            this.Clock.Stop();
            var frm = new ExitRoomMenu();
            frm.Location = this.Location;
            frm.StartPosition = FormStartPosition.CenterScreen;
            frm.FormClosing += delegate { this.Show(); };
            this.Hide();
            frm.ShowDialog();
            if (globalVars.exitedRoom == true)
            {
                globalVars.isAdmin = false;
                globalVars.exitedRoom = false;
                exitRoom(sender, e);
                this.Close();
            }
            else
            {
                this.Clock.Start();
            }
        }

        private void exitRoom(object sender, EventArgs e)
        {
            this.Clock.Stop();
            this._communicator.sendMsg(Serializer.serializeExitRoom(this._roomName));
            string serverMsg = this._communicator.recvMsg();
            if (deserializer.getMSGcode(serverMsg) == ((int)codeTypes.EXIT_ROOM))
            {
                ExitRoomRespHolder tmp = deserializer.deserializeExitRoomResponse(serverMsg);
                if (tmp.status == 0)
                {
                    var frm = new ShowErrorForm("Error exiting the room...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void waitingRoomForm_Load(object sender, EventArgs e)
        {
            if (globalVars.isAdmin)
            {
                this.questionTimeHolder.ReadOnly = false;
                this.NumOfQuestionsHolder.ReadOnly = false;
                this.maxPlayersHolder.ReadOnly = false;
            }
            else
            {
                this.questionTimeHolder.ReadOnly = true;
                this.NumOfQuestionsHolder.ReadOnly = true;
                this.maxPlayersHolder.ReadOnly = true;
            }
            updateFormValues(sender, e); // updated the form state
            this.Clock = new Timer();
            this.Clock.Interval = 3000; // 3 seconds || change if you want the update to occur in shorter time
            this.Clock.Start();
            this.Clock.Tick += new EventHandler(updateFormValues);
        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void showPass1_Click(object sender, EventArgs e)
        {
            this.Clock.Stop();
            if (globalVars.isAdmin == false)
            {
                var frm = new ShowErrorForm("Only the admin of the room can change its settings...");
                frm.Location = this.Location;
                frm.StartPosition = FormStartPosition.CenterScreen;
                frm.FormClosing += delegate { this.Show(); };
                this.Hide();
                frm.ShowDialog();
                this.Clock.Start();
                return;
            }
            { // input text holder checks
                if (this.maxPlayersHolder.Text == "" || !this.maxPlayersHolder.Text.All(char.IsDigit))
                {
                    MessageBox.Show("Max players field is not a number!!!", "Invalid value", MessageBoxButtons.OK);
                    this.Clock.Start();
                    return;
                }
                else if (int.Parse(this.maxPlayersHolder.Text) <= 0)
                {
                    MessageBox.Show("Max players must be 1 or higher!!!", "Invalid check", MessageBoxButtons.OK);
                    this.Clock.Start();
                    return;
                }
                else if (this.questionTimeHolder.Text == "" || !this.questionTimeHolder.Text.All(char.IsDigit))
                {
                    MessageBox.Show("Question time field is not a number!!!", "Invalid value", MessageBoxButtons.OK);
                    this.Clock.Start();
                    return;
                }
                else if (int.Parse(this.questionTimeHolder.Text) <= 0)
                {
                    MessageBox.Show("Question time must be 1 or higher!!!", "Invalid check", MessageBoxButtons.OK);
                    this.Clock.Start();
                    return;
                }
                else if (this.NumOfQuestionsHolder.Text == "" || !this.NumOfQuestionsHolder.Text.All(char.IsDigit))
                {
                    MessageBox.Show("Question count field is not a number!!!", "Invalid value", MessageBoxButtons.OK);
                    this.Clock.Start();
                    return;
                }
                else if (int.Parse(this.NumOfQuestionsHolder.Text) <= 0)
                {
                    MessageBox.Show("Question count must be 1 or higher!!!", "Invalid check", MessageBoxButtons.OK);
                    this.Clock.Start();
                    return;
                }
            }
            // send a update room mesaage
            this._communicator.sendMsg(Serializer.serializeUpdateRoom(this._roomName,
                int.Parse(this.maxPlayersHolder.Text),
                int.Parse(this.NumOfQuestionsHolder.Text),
                int.Parse(this.questionTimeHolder.Text)));
            string serverMsg = this._communicator.recvMsg();
            if (deserializer.getMSGcode(serverMsg) == ((int)codeTypes.UPDATE_ROOM_SETTINGS))
            {
                UpdateRoomRespHolder tmp = deserializer.deserializeUpdateRoomResp(serverMsg);
                if (tmp.status == 0)
                {
                    var frm = new ShowErrorForm("Error updating room...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
            }
            else
            {
                var frm = new ShowErrorForm(deserializer.deserializeErrorResp(serverMsg).message);
                frm.Location = this.Location;
                frm.StartPosition = FormStartPosition.CenterScreen;
                frm.FormClosing += delegate { this.Show(); };
                this.Hide();
                frm.ShowDialog();
            }
            this.Clock.Start();
        }

        private void playersConnectedDisplay_TextChanged(object sender, EventArgs e)
        {

        }

        private void updateFormValues(object sender, EventArgs e)
        {
            if (this.ActiveControl == this.questionTimeHolder ||
                this.ActiveControl == this.NumOfQuestionsHolder ||
                this.ActiveControl == this.maxPlayersHolder)
            {
                return;
            }
            // sends get players in room request to the server
            this._communicator.sendMsg(Serializer.serializeGetPlayersInRoom(this._roomName));
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
                string resp = deserializer.deserializeGetPlayersInRoomResp(serverMsg).players;
                string[] players = resp.Split(',');
                // now will be a display holder
                resp = "";
                usersHolder.Items.Clear();
                foreach (string p in players)
                {
                    usersHolder.Items.Add("- " + p);
                }
            }
            // after updating active players in room we update the room settings
            this._communicator.sendMsg(Serializer.serializeGetRoomData(this._roomName));
            serverMsg = this._communicator.recvMsg();
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
                GetRoomDataRespHolder resp = deserializer.deserializeGetRoomDataResponse(serverMsg);
                if (resp.status == 99)
                {
                    if (this.Clock != null)
                    {
                        this.Clock.Stop();
                    }

                    exitRoom(sender, e);
                    var frm = new ShowErrorForm("Room had been aborted by the host...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                    globalVars.isAdmin = false;
                    this.Close();
                }
                this._timePerQuestion = resp.answerTimeout;
                this.questionTimeHolder.Text = resp.answerTimeout.ToString();
                this.NumOfQuestionsHolder.Text = resp.questionCount.ToString();
                this.maxPlayersHolder.Text = resp.maxPlayers.ToString();
                if(resp.status == 1)
                {
                    this.Clock.Stop();
                    var frm = new GameForm(this._communicator, 5, this._timePerQuestion);
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                    this.Close();
                }
            }
        }

        private void roundedButton2_Click(object sender, EventArgs e)
        {

        }

        private void roundedButton3_Click(object sender, EventArgs e)
        {
            // start game button
            this.Clock.Stop();
            if (globalVars.isAdmin)
            {
                this._communicator.sendMsg(Serializer.serializeStartGame());
                string serverMsg = this._communicator.recvMsg();
                if(deserializer.getMSGcode(serverMsg) == ((int)codeTypes.ERROR_CODE))
                {
                    var frm = new ShowErrorForm(deserializer.deserializeErrorResp(serverMsg).message);
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                    this.Clock.Start();
                    return;
                }
                else
                {
                    var frm = new GameForm(this._communicator, 5, this._timePerQuestion);
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                    this.Close();
                }
            }
            else
            {
                var frm = new ShowErrorForm("Only the admin of the room can start the game...");
                frm.Location = this.Location;
                frm.StartPosition = FormStartPosition.CenterScreen;
                frm.FormClosing += delegate { this.Show(); };
                this.Hide();
                frm.ShowDialog();
                this.Clock.Start();
                return;
            }
        }
    }
}
