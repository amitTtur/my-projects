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
    public partial class displayRoomsForm : Form
    {
        ServerCommunicator _communicator;
        string[] roomsNames;


        public displayRoomsForm()
        {
            InitializeComponent();
        }
        public displayRoomsForm(ServerCommunicator communicator)
        {
            InitializeComponent();
            _communicator = communicator;
        }

        private void displayRoomsForm_Load(object sender, EventArgs e)
        {
            refreshRoomHolder(sender, e);
        }

        private void roomHolder_SelectedIndexChanged(object sender, EventArgs e)
        {
            this.roomHolder.ForeColor = Color.Red;
        }

        private void roundedButton1_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void joinRoomButton_Click(object sender, EventArgs e)
        {
            if(this.roomHolder.SelectedItem == null)
            {
                var frm = new ShowErrorForm("You didn't select any room...");
                frm.Location = this.Location;
                frm.StartPosition = FormStartPosition.CenterScreen;
                frm.FormClosing += delegate { this.Show(); };
                this.Hide();
                frm.ShowDialog();
                return;
            }
            // send the server a join room request
            this._communicator.sendMsg(Serializer.serializeJoinRoom(this.roomHolder.SelectedItem.ToString()));
            string s = this._communicator.recvMsg();

            if (deserializer.getMSGcode(s) == ((short)codeTypes.ERROR_CODE))
            {
                var frm = new ShowErrorForm(deserializer.deserializeErrorResp(s).message);
                frm.Location = this.Location;
                frm.StartPosition = FormStartPosition.CenterScreen;
                frm.FormClosing += delegate { this.Show(); };
                this.Hide();
                frm.ShowDialog();
                this.refreshRoomHolder(sender,e);
            }
            else
            {
                JoinRoomRespHolder tmp = deserializer.deserializeJoinRoomResponse(s);
                if (tmp.status == 1)
                {
                    var frm = new waitingRoomForm(this._communicator, this.roomHolder.SelectedItem.ToString());
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                }
                else
                {
                    var frm = new ShowErrorForm("Error joining room...");
                    frm.Location = this.Location;
                    frm.StartPosition = FormStartPosition.CenterScreen;
                    frm.FormClosing += delegate { this.Show(); };
                    this.Hide();
                    frm.ShowDialog();
                    this.refreshRoomHolder(sender, e);
                }
            }
        }

        private void roundedButton2_Click(object sender, EventArgs e)
        {
            refreshRoomHolder(sender, e); // refreshing active rooms
        }

        private void refreshRoomHolder(object sender, EventArgs e)
        {
            this._communicator.sendMsg(Serializer.toProtocol(((int)codeTypes.GET_ROOM), 0));
            string s = this._communicator.recvMsg();

            if(deserializer.getMSGcode(s) == ((short)codeTypes.ERROR_CODE)) 
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
                GetRoomRespHolder tmp = deserializer.deserializeGetRoomsResponse(s);
                string[] roomsArr = tmp.rooms.Split(",");
                this.roomHolder.Items.Clear();
                foreach (string room in roomsArr)
                {
                    this.roomHolder.Items.Add(room);
                }
            }
        }
    }
}
