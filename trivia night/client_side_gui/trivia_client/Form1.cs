using System.Runtime.CompilerServices;

namespace trivia_client
{

    public partial class Form1 : Form
    {
        private ServerCommunicator _communicator;
        public Form1(ServerCommunicator client)
        {
            InitializeComponent();
            this._communicator = client;
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            this._communicator.sendExitMsg();
            this._communicator.recvMsg();
            Application.Exit();
        }

        private void createButton_Click(object sender, EventArgs e)
        {
            var frm = new SignUpForm(this._communicator);
            frm.Location = this.Location;
            frm.StartPosition = FormStartPosition.Manual;
            frm.FormClosing += delegate { this.Show(); };
            frm.Show();
            this.Hide();
        }

        private void loginButton_Click(object sender, EventArgs e)
        {
            this._communicator.sendMsg(Serializer.serializeLogin(usernameHolder.Text, passHolder.Text));
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
                loginRespHolder tmp = deserializer.deserializeLoginResp(serverMsg);
                if (tmp.status == 1)
                {
                    globalVars.activeUserName = this.usernameHolder.Text;
                    var frm = new MenuForm(this._communicator);
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                    if (globalVars.exitRequested)
                    {
                        Application.Exit();
                    }
                }
                else
                {
                    var frm = new ShowErrorForm("error in the login please try again...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
            }
            if (globalVars.exitRequested)
            {
                Application.Exit();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.passHolder.UseSystemPasswordChar = true;
            showPass1.Text = "( - )";
        }

        private void roundedButton2_Click(object sender, EventArgs e)
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
    }
}