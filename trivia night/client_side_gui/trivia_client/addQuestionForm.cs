using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace trivia_client
{
    public partial class addQuestionForm : Form
    {
        ServerCommunicator _communicator;
        public addQuestionForm(ServerCommunicator communicator)
        {
            InitializeComponent();
            _communicator = communicator;
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void submitionButton_Click(object sender, EventArgs e)
        {
            // text fields input checkers
            {
                if (this.AnswerHolder.Text.Contains("@#@#@"))
                {
                    var frm = new ShowErrorForm("answers field cant contain a '@#@#@' sequence...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                    return;
                }
                else if (this.a1Holder.Text.Contains("@#@#@"))
                {
                    var frm = new ShowErrorForm("answers field cant contain a '@#@#@' sequence...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                    return;
                }
                else if (this.a2Holder.Text.Contains("@#@#@"))
                {
                    var frm = new ShowErrorForm("answers field cant contain a '@#@#@' sequence...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                    return;
                }
                else if (this.a3Holder.Text.Contains("@#@#@"))
                {
                    var frm = new ShowErrorForm("answers field cant contain a '@#@#@' sequence...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                    return;
                }
                else if (string.IsNullOrEmpty(this.QuestionHolder.Text) || string.IsNullOrEmpty(this.AnswerHolder.Text) ||
                    string.IsNullOrEmpty(this.a1Holder.Text) || string.IsNullOrEmpty(this.a2Holder.Text) ||
                    string.IsNullOrEmpty(this.a3Holder.Text))
                {
                    var frm = new ShowErrorForm("Fields cant be empty...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                    return;
                }
            }

            // send the server a request
            this._communicator.sendMsg(Serializer.serializeAddQuestion(this.AnswerHolder.Text,
                this.a1Holder.Text, this.a2Holder.Text, this.a3Holder.Text, this.QuestionHolder.Text));

            //  receives the answer
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
                AddQuestionRespHolder resp = deserializer.deserializeAddQuestionResponse(serverMsg);
                if (resp.status == 0)
                {
                    var frm = new ShowErrorForm("Error adding question...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
                else
                {
                    var frm = new ShowErrorForm("Question Added successfully!");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
            }
            this.Close();
        }

        private void addQuestionForm_Load(object sender, EventArgs e)
        {

        }
    }
}
