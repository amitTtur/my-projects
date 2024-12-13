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
    public partial class personalStatsForm : Form
    {
        ServerCommunicator _communicator;
        public personalStatsForm(ServerCommunicator communicator)
        {
            InitializeComponent();
            _communicator = communicator;
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void personalStatsForm_Load(object sender, EventArgs e)
        {
            // receiving the user personal stats
            this._communicator.sendMsg(Serializer.toProtocol(((int)codeTypes.GET_PERSONAL_STATS), 0));
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
                GetPersonalStatsRespHolder tmp = deserializer.deserializeGetPersonalStatsResponse(s);
                if (tmp.status == 0)
                {
                    var frm = new ShowErrorForm("Error fetching stats...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
                else
                {
                    Dictionary<string, double> stats = new Dictionary<string, double>();
                    stats = tmp.userStats.Split(',').Select(pair => pair.Split('^')).ToDictionary(parts => parts[0], parts => double.Parse(parts[1]));

                    this.gamesPlayedHolder.Text = ((int)stats["Games"]).ToString();
                    this.bestScoreHolder.Text = ((int)stats["BestScore"]).ToString();
                    this.correctAnsHolder.Text = ((int)stats["NumberOfCorrectAns"]).ToString();
                    this.totalQAnsHolder.Text = ((int)stats["TotalQuestionsAnswered"]).ToString();
                    this.avgTimeToAnsHolder.Text = stats["AvgTimeToAnswer"].ToString("F");
                }
            }
        }
    }
}
