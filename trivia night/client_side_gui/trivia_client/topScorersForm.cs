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
    public partial class topScorersForm : Form
    {
        ServerCommunicator _communicator;
        public topScorersForm(ServerCommunicator communicator)
        {
            InitializeComponent();
            this._communicator = communicator;
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void top1Holder_TextChanged(object sender, EventArgs e)
        {

        }

        private void topScorersForm_Load(object sender, EventArgs e)
        {
            // send a getTop5 request to the server 
            this._communicator.sendMsg(Serializer.toProtocol(((int)codeTypes.GET_TOP5), 0));
            string s = this._communicator.recvMsg();

            if (deserializer.getMSGcode(s) == ((int)codeTypes.ERROR_CODE))
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
                GetTop5RespHolder tmp = deserializer.deserializeGetTop5Response(s);
                if (tmp.status == 0)
                {
                    var frm = new ShowErrorForm("Error fetching top 5...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
                else
                {
                    Dictionary<string, int> users = new Dictionary<string, int>();
                    users = tmp.highScores.Split(',').Select(pair => pair.Split('^')).ToDictionary(parts => parts[0], parts => int.Parse(parts[1]));

                    this.top1Holder.Text = users.ElementAt(4).Key + " - " + users.ElementAt(4).Value.ToString();
                    this.top2Holder.Text = users.ElementAt(3).Key + " - " + users.ElementAt(3).Value.ToString();
                    this.top3Holder.Text = users.ElementAt(2).Key + " - " + users.ElementAt(2).Value.ToString();
                    this.top4Holder.Text = users.ElementAt(1).Key + " - " + users.ElementAt(1).Value.ToString();
                    this.top5Holder.Text = users.ElementAt(0).Key + " - " + users.ElementAt(0).Value.ToString();
                }
            }

        }
    }
}
