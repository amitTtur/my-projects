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
    public partial class EndGameForm : Form
    {
        private ServerCommunicator _communicator;
        public EndGameForm(ServerCommunicator communicator)
        {
            InitializeComponent();
            _communicator = communicator;
        }

        private void exitButtton_Click(object sender, EventArgs e)
        {
            // send a leave room request
            this._communicator.sendMsg(Serializer.serializeLeaveGame());
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
                this.Close();
            }
        }

        private void EndGameForm_Load(object sender, EventArgs e)
        {
            // receiving and displays the end game results
            this._communicator.sendMsg(Serializer.serializeGameResults());
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
                GameResultRespHolder resp = deserializer.deserializeGetGameResultsResponse(serverMsg);
                string[] usersStats = resp.results.Split("@#@#@");
                string activeUserStats = "";
                int firstI = -1, secondI = -1, thirdI = -1;
                int firstScore = -1, secondScore = -1, thirdScore = -1;
                for(int i = 0; i < usersStats.Length; i++)
                {
                    string[] tmp = usersStats[i].Split("-");
                    int tmpScore = int.Parse(tmp[1]);
                    if(tmpScore > firstScore)
                    {
                        thirdScore = secondScore;
                        secondScore = firstScore;
                        firstScore = tmpScore;
                        //
                        thirdI = secondI;
                        secondI = firstI;
                        firstI = i;
                    }
                    else if(tmpScore > secondScore)
                    {
                        thirdScore = secondScore;
                        secondScore = tmpScore;
                        //
                        thirdI = secondI;
                        secondI = i;
                    }
                    else if (tmpScore > thirdScore)
                    {
                        thirdScore = tmpScore;
                        // 
                        thirdI = i;
                    }

                    if (tmp[0] == globalVars.activeUserName)
                    {
                        activeUserStats = tmp[0] + "-" + tmp[1]; 
                    }
                }
                this.personalScoreHolder.Text = activeUserStats;
                this.place1holder.Text = usersStats[firstI];
                if(secondI == -1)
                {
                    this.place2holder.Text = "None-0";
                }
                else
                {
                    this.place2holder.Text = usersStats[secondI];
                }
                if (thirdI == -1)
                {
                    this.place3holder.Text = "None-0";
                }
                else
                {
                    this.place3holder.Text = usersStats[thirdI];
                }
            }
        }
    }
}
