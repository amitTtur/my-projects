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
    public partial class MenuForm : Form
    {
        ServerCommunicator _communicator;
        public MenuForm(ServerCommunicator communicator)
        {
            InitializeComponent();
            _communicator = communicator;
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            var frm = new LogoutOrExitForm(this._communicator);
            frm.Location = this.Location;
            frm.StartPosition = FormStartPosition.CenterScreen;
            frm.FormClosing += delegate { this.Show(); };
            this.Hide();
            frm.ShowDialog();
            if (globalVars.exitRequested || globalVars.logoutRequested)
            {
                this.Close();
                globalVars.logoutRequested = false;
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void roundedButton3_Click(object sender, EventArgs e)
        {
            var frm = new CreateRoomForm(this._communicator);
            frm.Location = this.Location;
            frm.StartPosition = FormStartPosition.CenterScreen;
            frm.FormClosing += delegate { this.Show(); };
            this.Hide();
            frm.ShowDialog();
        }

        private void roundedButton2_Click(object sender, EventArgs e)
        {
            var frm = new displayRoomsForm(this._communicator);
            frm.Location = this.Location;
            frm.StartPosition = FormStartPosition.CenterScreen;
            frm.FormClosing += delegate { this.Show(); };
            this.Hide();
            frm.ShowDialog();
        }

        private void roundedButton4_Click(object sender, EventArgs e)
        {
            var frm = new personalStatsForm(this._communicator);
            frm.Location = this.Location;
            frm.StartPosition = FormStartPosition.CenterScreen;
            frm.FormClosing += delegate { this.Show(); };
            this.Hide();
            frm.ShowDialog();
        }

        private void roundedButton5_Click(object sender, EventArgs e)
        {
            var frm = new topScorersForm(this._communicator);
            frm.Location = this.Location;
            frm.StartPosition = FormStartPosition.CenterScreen;
            frm.FormClosing += delegate { this.Show(); };
            this.Hide();
            frm.ShowDialog();
        }

        private void MenuForm_Load(object sender, EventArgs e)
        {

        }

        private void roundedButton6_Click(object sender, EventArgs e)
        {
            var frm = new addQuestionForm(this._communicator);
            frm.Location = this.Location;
            frm.StartPosition = FormStartPosition.CenterScreen;
            frm.FormClosing += delegate { this.Show(); };
            this.Hide();
            frm.ShowDialog();
        }
    }
}
