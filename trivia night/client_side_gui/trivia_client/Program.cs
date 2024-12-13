using Newtonsoft.Json;
using System.Text.Json.Nodes;

using System.Net;
using System.Net.Sockets;
using System.Threading;


namespace trivia_client
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            // listening to the server port in the local network
            ServerCommunicator client = new ServerCommunicator("127.0.0.1",8826);
            ApplicationConfiguration.Initialize();
            // starting the app
            Application.Run(new Form1(client));
        }
    }
}