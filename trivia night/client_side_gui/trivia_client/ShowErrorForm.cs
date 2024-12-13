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
    public partial class ShowErrorForm : Form
    {
        public ShowErrorForm()
        {
            InitializeComponent();
            errorTextBox.Text = "Unexpected error occurred...";
        }

        public ShowErrorForm(string errorMessage)
        {
            InitializeComponent();
            errorTextBox.Text = errorMessage;
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void ShowErrorForm_Load(object sender, EventArgs e)
        {

        }
    }
}
