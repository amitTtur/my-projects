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
    public partial class ExitRoomMenu : Form
    {
        public ExitRoomMenu()
        {
            InitializeComponent();
        }

        private void roundedButton2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            globalVars.exitedRoom = true;
            this.Close();
        }
    }
}
