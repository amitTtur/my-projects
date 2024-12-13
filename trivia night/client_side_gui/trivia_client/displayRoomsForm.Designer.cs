namespace trivia_client
{
    partial class displayRoomsForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            roundedButton1 = new designs.RoundedButton();
            label2 = new Label();
            roomHolder = new ListBox();
            joinRoomButton = new designs.RoundedButton();
            roundedButton2 = new designs.RoundedButton();
            SuspendLayout();
            // 
            // roundedButton1
            // 
            roundedButton1.BackColor = Color.Red;
            roundedButton1.BackgroundColor = Color.Red;
            roundedButton1.BorderColor = Color.Transparent;
            roundedButton1.BorderRadius = 20;
            roundedButton1.BorderSize = 0;
            roundedButton1.FlatAppearance.BorderSize = 0;
            roundedButton1.FlatStyle = FlatStyle.Flat;
            roundedButton1.ForeColor = Color.White;
            roundedButton1.Location = new Point(825, 12);
            roundedButton1.Name = "roundedButton1";
            roundedButton1.RightToLeft = RightToLeft.Yes;
            roundedButton1.Size = new Size(43, 42);
            roundedButton1.TabIndex = 2;
            roundedButton1.TextColor = Color.White;
            roundedButton1.UseVisualStyleBackColor = false;
            roundedButton1.Click += roundedButton1_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Monotype Corsiva", 25F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.WhiteSmoke;
            label2.Location = new Point(32, 34);
            label2.Name = "label2";
            label2.Size = new Size(778, 60);
            label2.TabIndex = 4;
            label2.Text = "Please choose the room you want to join!";
            // 
            // roomHolder
            // 
            roomHolder.BackColor = Color.DarkGray;
            roomHolder.BorderStyle = BorderStyle.None;
            roomHolder.ColumnWidth = 10;
            roomHolder.Font = new Font("Monotype Corsiva", 16F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            roomHolder.ForeColor = Color.WhiteSmoke;
            roomHolder.FormattingEnabled = true;
            roomHolder.ImeMode = ImeMode.NoControl;
            roomHolder.ItemHeight = 39;
            roomHolder.Items.AddRange(new object[] { "room1", "room2", "room3", "room4", "room7", "room9" });
            roomHolder.Location = new Point(251, 134);
            roomHolder.Margin = new Padding(100);
            roomHolder.Name = "roomHolder";
            roomHolder.Size = new Size(339, 312);
            roomHolder.Sorted = true;
            roomHolder.TabIndex = 5;
            roomHolder.SelectedIndexChanged += roomHolder_SelectedIndexChanged;
            // 
            // joinRoomButton
            // 
            joinRoomButton.BackColor = Color.WhiteSmoke;
            joinRoomButton.BackgroundColor = Color.WhiteSmoke;
            joinRoomButton.BorderColor = Color.Aquamarine;
            joinRoomButton.BorderRadius = 15;
            joinRoomButton.BorderSize = 0;
            joinRoomButton.FlatAppearance.BorderSize = 0;
            joinRoomButton.FlatStyle = FlatStyle.Flat;
            joinRoomButton.Font = new Font("David", 15F, FontStyle.Bold, GraphicsUnit.Point);
            joinRoomButton.ForeColor = Color.Red;
            joinRoomButton.Location = new Point(273, 512);
            joinRoomButton.Name = "joinRoomButton";
            joinRoomButton.Size = new Size(286, 64);
            joinRoomButton.TabIndex = 7;
            joinRoomButton.Text = "Join room";
            joinRoomButton.TextColor = Color.Red;
            joinRoomButton.UseVisualStyleBackColor = false;
            joinRoomButton.Click += joinRoomButton_Click;
            // 
            // roundedButton2
            // 
            roundedButton2.BackColor = Color.Red;
            roundedButton2.BackgroundColor = Color.Red;
            roundedButton2.BorderColor = Color.Aquamarine;
            roundedButton2.BorderRadius = 15;
            roundedButton2.BorderSize = 0;
            roundedButton2.FlatAppearance.BorderSize = 0;
            roundedButton2.FlatStyle = FlatStyle.Flat;
            roundedButton2.Font = new Font("David", 12F, FontStyle.Bold, GraphicsUnit.Point);
            roundedButton2.ForeColor = Color.WhiteSmoke;
            roundedButton2.Location = new Point(307, 455);
            roundedButton2.Name = "roundedButton2";
            roundedButton2.Size = new Size(222, 34);
            roundedButton2.TabIndex = 8;
            roundedButton2.Text = "Refresh";
            roundedButton2.TextColor = Color.WhiteSmoke;
            roundedButton2.UseVisualStyleBackColor = false;
            roundedButton2.Click += roundedButton2_Click;
            // 
            // displayRoomsForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(880, 600);
            Controls.Add(roundedButton2);
            Controls.Add(joinRoomButton);
            Controls.Add(roomHolder);
            Controls.Add(label2);
            Controls.Add(roundedButton1);
            FormBorderStyle = FormBorderStyle.None;
            Name = "displayRoomsForm";
            Text = "displayRoomsForm";
            Load += displayRoomsForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private designs.RoundedButton roundedButton1;
        private Label label2;
        private ListBox roomHolder;
        private designs.RoundedButton joinRoomButton;
        private designs.RoundedButton roundedButton2;
    }
}