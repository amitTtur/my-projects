using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace trivia_client
{
    public class ServerCommunicator
    {
        private string _serverAddress;
        private int _portNumber;

        // connection vars
        private TcpClient _tcpClient;
        private IPEndPoint _serverEndPoint;
        private NetworkStream _clientStream;

        public ServerCommunicator(string serverAddress, int portNumber)
        {
            this._serverAddress = serverAddress;
            this._portNumber = portNumber;

            if (!this.connectToServer())
            {
                throw new Exception("Server connection failure");
            }
        }

        public bool connectToServer()
        {
            try
            {
                this._tcpClient = new TcpClient();
                this._serverEndPoint = new IPEndPoint(IPAddress.Parse(this._serverAddress), this._portNumber);
                this._tcpClient.Connect(this._serverEndPoint);
                this._clientStream = this._tcpClient.GetStream();
            }
            catch 
            {
                return false;
            }
            return true;
        }

        public void sendMsg(string msg)
        {
            byte[] buffer = new ASCIIEncoding().GetBytes(msg.ToCharArray());
            this._clientStream.Write(buffer, 0, buffer.Length);
            this._clientStream.Flush();
        }

        public void sendExitMsg()
        {
            string s = Serializer.toProtocol(((short)codeTypes.DATA_FILLER), 0);
            byte[] buffer = new ASCIIEncoding().GetBytes(s.ToCharArray());
            this._clientStream.Write(buffer, 0, buffer.Length);
            this._clientStream.Flush();
        }

        public string recvMsg()
        {
            byte[] buffer = new byte[1024];
            this._clientStream.Read(buffer, 0, 1024);
            StringBuilder result = new StringBuilder();
            foreach (byte b in buffer)
            {
                result.Append((char)b);  // Cast to char for string representation (optional)
            }

            return result.ToString();
        }
    }
}
