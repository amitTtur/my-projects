namespace trivia_client
{
    partial class waitingRoomForm
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
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            label6 = new Label();
            label7 = new Label();
            NumOfQuestionsHolder = new TextBox();
            maxPlayersHolder = new TextBox();
            questionTimeHolder = new TextBox();
            updateButton = new designs.RoundedButton();
            label5 = new Label();
            usersHolder = new ListBox();
            roundedButton2 = new designs.RoundedButton();
            roundedButton3 = new designs.RoundedButton();
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
            roundedButton1.TabIndex = 5;
            roundedButton1.TextColor = Color.White;
            roundedButton1.UseVisualStyleBackColor = false;
            roundedButton1.Click += roundedButton1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Monotype Corsiva", 50F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.WhiteSmoke;
            label1.Location = new Point(169, -2);
            label1.Name = "label1";
            label1.Size = new Size(554, 122);
            label1.TabIndex = 6;
            label1.Text = "Waiting room";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("David", 15F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.Red;
            label2.Location = new Point(242, 120);
            label2.Name = "label2";
            label2.Size = new Size(434, 29);
            label2.TabIndex = 7;
            label2.Text = "Please wait until the match starts";
            label2.Click += label2_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Monotype Corsiva", 19F, FontStyle.Bold, GraphicsUnit.Point);
            label3.ForeColor = Color.WhiteSmoke;
            label3.Location = new Point(12, 190);
            label3.Name = "label3";
            label3.Size = new Size(281, 46);
            label3.TabIndex = 8;
            label3.Text = "Users in the room:";
            label3.TextAlign = ContentAlignment.MiddleLeft;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("David", 13F, FontStyle.Bold, GraphicsUnit.Point);
            label4.ForeColor = Color.Brown;
            label4.Location = new Point(522, 302);
            label4.Name = "label4";
            label4.Size = new Size(150, 25);
            label4.TabIndex = 10;
            label4.Text = "Max players";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("David", 13F, FontStyle.Bold, GraphicsUnit.Point);
            label6.ForeColor = Color.Brown;
            label6.Location = new Point(497, 357);
            label6.Name = "label6";
            label6.Size = new Size(175, 25);
            label6.TabIndex = 12;
            label6.Text = "Question Time";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("David", 13F, FontStyle.Bold, GraphicsUnit.Point);
            label7.ForeColor = Color.Brown;
            label7.Location = new Point(430, 249);
            label7.Name = "label7";
            label7.Size = new Size(242, 25);
            label7.TabIndex = 13;
            label7.Text = "Number of questions";
            label7.Click += label7_Click;
            // 
            // NumOfQuestionsHolder
            // 
            NumOfQuestionsHolder.Location = new Point(711, 249);
            NumOfQuestionsHolder.Name = "NumOfQuestionsHolder";
            NumOfQuestionsHolder.Size = new Size(150, 31);
            NumOfQuestionsHolder.TabIndex = 15;
            // 
            // maxPlayersHolder
            // 
            maxPlayersHolder.Location = new Point(711, 302);
            maxPlayersHolder.Name = "maxPlayersHolder";
            maxPlayersHolder.Size = new Size(150, 31);
            maxPlayersHolder.TabIndex = 16;
            // 
            // questionTimeHolder
            // 
            questionTimeHolder.Location = new Point(711, 353);
            questionTimeHolder.Name = "questionTimeHolder";
            questionTimeHolder.Size = new Size(150, 31);
            questionTimeHolder.TabIndex = 17;
            // 
            // updateButton
            // 
            updateButton.BackColor = Color.Red;
            updateButton.BackgroundColor = Color.Red;
            updateButton.BorderColor = Color.Aquamarine;
            updateButton.BorderRadius = 15;
            updateButton.BorderSize = 0;
            updateButton.FlatAppearance.BorderSize = 0;
            updateButton.FlatStyle = FlatStyle.Flat;
            updateButton.Font = new Font("Segoe UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            updateButton.ForeColor = Color.WhiteSmoke;
            updateButton.Location = new Point(650, 405);
            updateButton.Name = "updateButton";
            updateButton.Size = new Size(199, 46);
            updateButton.TabIndex = 18;
            updateButton.Text = "update settings";
            updateButton.TextColor = Color.WhiteSmoke;
            updateButton.UseVisualStyleBackColor = true;
            updateButton.Click += showPass1_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Monotype Corsiva", 19F, FontStyle.Bold, GraphicsUnit.Point);
            label5.ForeColor = Color.WhiteSmoke;
            label5.Location = new Point(599, 190);
            label5.Name = "label5";
            label5.Size = new Size(135, 46);
            label5.TabIndex = 19;
            label5.Text = "Settings";
            label5.TextAlign = ContentAlignment.MiddleLeft;
            // 
            // usersHolder
            // 
            usersHolder.BackColor = Color.DimGray;
            usersHolder.Font = new Font("David", 10F, FontStyle.Bold, GraphicsUnit.Point);
            usersHolder.ForeColor = Color.WhiteSmoke;
            usersHolder.FormattingEnabled = true;
            usersHolder.ItemHeight = 20;
            usersHolder.Location = new Point(29, 239);
            usersHolder.Name = "usersHolder";
            usersHolder.SelectionMode = SelectionMode.None;
            usersHolder.Size = new Size(250, 324);
            usersHolder.Sorted = true;
            usersHolder.TabIndex = 20;
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
            roundedButton2.Font = new Font("Segoe UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            roundedButton2.ForeColor = Color.WhiteSmoke;
            roundedButton2.Location = new Point(504, 412);
            roundedButton2.Name = "roundedButton2";
            roundedButton2.Size = new Size(140, 32);
            roundedButton2.TabIndex = 21;
            roundedButton2.Text = "Cancel";
            roundedButton2.TextColor = Color.WhiteSmoke;
            roundedButton2.UseVisualStyleBackColor = true;
            roundedButton2.Click += roundedButton2_Click;
            // 
            // roundedButton3
            // 
            roundedButton3.BackColor = Color.WhiteSmoke;
            roundedButton3.BackgroundColor = Color.WhiteSmoke;
            roundedButton3.BorderColor = Color.Aquamarine;
            roundedButton3.BorderRadius = 15;
            roundedButton3.BorderSize = 0;
            roundedButton3.FlatAppearance.BorderSize = 0;
            roundedButton3.FlatStyle = FlatStyle.Flat;
            roundedButton3.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            roundedButton3.ForeColor = Color.Red;
            roundedButton3.Location = new Point(430, 501);
            roundedButton3.Name = "roundedButton3";
            roundedButton3.Size = new Size(266, 53);
            roundedButton3.TabIndex = 22;
            roundedButton3.Text = "Start Game";
            roundedButton3.TextColor = Color.Red;
            roundedButton3.UseVisualStyleBackColor = false;
            roundedButton3.Click += roundedButton3_Click;
            // 
            // waitingRoomForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(880, 600);
            Controls.Add(roundedButton3);
            Controls.Add(roundedButton2);
            Controls.Add(usersHolder);
            Controls.Add(label5);
            Controls.Add(updateButton);
            Controls.Add(questionTimeHolder);
            Controls.Add(maxPlayersHolder);
            Controls.Add(NumOfQuestionsHolder);
            Controls.Add(label7);
            Controls.Add(label6);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(roundedButton1);
            FormBorderStyle = FormBorderStyle.None;
            Name = "waitingRoomForm";
            Text = "waitingRoomForm";
            Load += waitingRoomForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private designs.RoundedButton roundedButton1;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label6;
        private Label label7;
        private TextBox NumOfQuestionsHolder;
        private TextBox maxPlayersHolder;
        private TextBox questionTimeHolder;
        private designs.RoundedButton updateButton;
        private Label label5;
        private ListBox usersHolder;
        private designs.RoundedButton roundedButton2;
        private designs.RoundedButton roundedButton3;
    }
}