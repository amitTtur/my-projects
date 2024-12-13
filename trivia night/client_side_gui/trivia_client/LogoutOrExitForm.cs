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
    public partial class LogoutOrExitForm : Form
    {
        private ServerCommunicator _communicator;
        public LogoutOrExitForm(ServerCommunicator communicator)
        {
            InitializeComponent();
            _communicator = communicator;
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            this._communicator.sendExitMsg();
            this._communicator.recvMsg();
            globalVars.exitRequested = true;
            this.Close();
        }

        private void roundedButton2_Click(object sender, EventArgs e)
        {
            // sends a logout request
            string s = "";
            s = Serializer.toProtocol(((short)codeTypes.LOGOUT), 0);
            this._communicator.sendMsg(s);
            s = this._communicator.recvMsg();
            if (deserializer.getMSGcode(s) == ((short)codeTypes.LOGOUT))
            {
                LogoutRespHolder tmp = deserializer.deserializeLogoutResp(s);
                if (tmp.status == 1)
                {
                    this.Close();
                    globalVars.logoutRequested = true;
                }
                else
                {
                    var frm = new ShowErrorForm("Error logging out...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
            }
            else
            {
                var frm = new ShowErrorForm(deserializer.deserializeErrorResp(s).message);
                frm.Location = this.Location;
                frm.StartPosition = FormStartPosition.CenterScreen;
                frm.FormClosing += delegate { this.Show(); };
                this.Hide();
                frm.ShowDialog();
            }


        }

        private void roundedButton3_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void LogoutOrExitForm_Load(object sender, EventArgs e)
        {

        }
    }
}
