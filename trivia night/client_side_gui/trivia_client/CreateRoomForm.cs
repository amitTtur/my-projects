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
    public partial class CreateRoomForm : Form
    {
        ServerCommunicator _communicator;
        public CreateRoomForm()
        {
            InitializeComponent();
        }
        public CreateRoomForm(ServerCommunicator communicator)
        {
            InitializeComponent();
            _communicator = communicator;
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void usernameHolder_TextChanged(object sender, EventArgs e)
        {

        }

        private void registerButton_Click(object sender, EventArgs e)
        {
            // text input checkers
            {
                if (this.maxPlayersHolder.Text == "" || !this.maxPlayersHolder.Text.All(char.IsDigit))
                {
                    MessageBox.Show("Max players field is not a number!!!", "Invalid value", MessageBoxButtons.OK);
                    return;
                }
                else if (int.Parse(this.maxPlayersHolder.Text) <= 0)
                {
                    MessageBox.Show("Max players must be 1 or higher!!!", "Invalid check", MessageBoxButtons.OK);
                    return;
                }
                else if (this.roomNameHolder.Text == "")
                {
                    MessageBox.Show("Name field cannot be empty!!!", "Invalid value", MessageBoxButtons.OK);
                    return;
                }
                else if (this.roomNameHolder.Text.Contains(' '))
                {
                    MessageBox.Show("Name field cannot have a space (' ') in it!!!", "Invalid check", MessageBoxButtons.OK);
                    return;
                }
                else if (this.questionTimeHolder.Text == "" || !this.questionTimeHolder.Text.All(char.IsDigit))
                {
                    MessageBox.Show("Question time field is not a number!!!", "Invalid value", MessageBoxButtons.OK);
                    return;
                }
                else if (int.Parse(this.questionTimeHolder.Text) <= 0)
                {
                    MessageBox.Show("Question time must be 1 or higher!!!", "Invalid check", MessageBoxButtons.OK);
                    return;
                }
                else if (this.questionCountHolder.Text == "" || !this.questionCountHolder.Text.All(char.IsDigit))
                {
                    MessageBox.Show("Question count field is not a number!!!", "Invalid value", MessageBoxButtons.OK);
                    return;
                }
                else if (int.Parse(this.questionCountHolder.Text) <= 0)
                {
                    MessageBox.Show("Question count must be 1 or higher!!!", "Invalid check", MessageBoxButtons.OK);
                    return;
                }
            }


            // checks are finished. next

            // send the server a request
            this._communicator.sendMsg(Serializer.serializeCreateRoom(this.roomNameHolder.Text,
                int.Parse(this.maxPlayersHolder.Text),
                int.Parse(this.questionCountHolder.Text),
                int.Parse(this.questionTimeHolder.Text)));
            string s = this._communicator.recvMsg();

            if (deserializer.getMSGcode(s) == ((short)codeTypes.ERROR_CODE))
            {
                var frm = new ShowErrorForm(deserializer.deserializeErrorResp(s).message);
                frm.Location = this.Location;
                frm.StartPosition = FormStartPosition.CenterScreen;
                frm.FormClosing += delegate { this.Show(); };
                this.Hide();
                frm.ShowDialog();
            }
            else
            {
                createRoomRespHolder tmp = deserializer.deserializeCreateRoomResp(s);
                if (tmp.status == 0)
                {
                    var frm = new ShowErrorForm("General Error creating room...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
                else
                {
                    globalVars.isAdmin = true;
                    var frm = new waitingRoomForm(this._communicator, this.roomNameHolder.Text);
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
            }
        }

        private void CreateRoomForm_Load(object sender, EventArgs e)
        {

        }
    }
}
