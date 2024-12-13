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
    public partial class SignUpForm : Form
    {
        private ServerCommunicator _communicator;
        public SignUpForm(ServerCommunicator communicator)
        {
            InitializeComponent();
            this._communicator = communicator;
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void registerButton_Click(object sender, EventArgs e)
        {
            // standard special character in a keyboard
            string specialCharacters = "!@#$%^&*()_~`-=+|}{[]\'\"\\ :;<>,./?";

            // field checkers
            if (this.usernameHolder.Text == "")
            {
                MessageBox.Show("UserName Field is Empty!!!", "Invalid value", MessageBoxButtons.OK);
                return;
            }
            else if (this.usernameHolder.Text.Any(c => specialCharacters.Contains(c)))
            {
                MessageBox.Show("Username field cant contain a special character in it!!!", "Invalid check", MessageBoxButtons.OK);
                return;
            }
            else if (this.emailHolder.Text == "")
            {
                MessageBox.Show("Email Field is Empty!!!", "Invalid value", MessageBoxButtons.OK);
                return;
            }
            else if (this.passHolder.Text == "")
            {
                MessageBox.Show("Password Field is Empty!!!", "Invalid value", MessageBoxButtons.OK);
                return;
            }
            else if (this.confirmPassHolder.Text == "")
            {
                MessageBox.Show("Confirm Password Field is Empty!!!", "Invalid value", MessageBoxButtons.OK);
                return;
            }
            else if (this.passHolder.Text != this.confirmPassHolder.Text)
            {
                MessageBox.Show("Passwords don't match!!!", "Invalid check", MessageBoxButtons.OK);
                return;
            }
            else if (this.usernameHolder.Text.Contains(' ') ||
                this.passHolder.Text.Contains(' ') ||
                this.emailHolder.Text.Contains(' '))
            {
                MessageBox.Show("Field cant contain a space (' ') in it!!!", "Invalid check", MessageBoxButtons.OK);
                return;
            }            

            // send a signup request to the server
            this._communicator.sendMsg(Serializer.serializeSignUp(usernameHolder.Text, passHolder.Text, emailHolder.Text));
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
                SignUpRespHolder tmp = deserializer.deserializeSignUpResp(serverMsg);
                if (tmp.status == 1)
                {
                    this.Close();
                }
                else
                {
                    var frm = new ShowErrorForm("error in the signup please try again...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
            }
        }

        private void usernameHolder_TextChanged(object sender, EventArgs e)
        {

        }

        private void SignUpForm_Load(object sender, EventArgs e)
        {
            this.confirmPassHolder.UseSystemPasswordChar = true;
            showPass1.Text = "( - )";
            this.passHolder.UseSystemPasswordChar = true;
            showPass2.Text = "( - )";
        }

        private void showPass1_Click(object sender, EventArgs e)
        {
            if (showPass1.Text == "( - )")
            {
                this.passHolder.UseSystemPasswordChar = false;
                showPass1.Text = "( x )";
            }
            else
            {
                this.passHolder.UseSystemPasswordChar = true;
                showPass1.Text = "( - )";
            }
        }

        private void showPass2_Click(object sender, EventArgs e)
        {
            if (showPass2.Text == "( - )")
            {
                this.confirmPassHolder.UseSystemPasswordChar = false;
                showPass2.Text = "( x )";
            }
            else
            {
                this.confirmPassHolder.UseSystemPasswordChar = true;
                showPass2.Text = "( - )";
            }
        }
    }
}
