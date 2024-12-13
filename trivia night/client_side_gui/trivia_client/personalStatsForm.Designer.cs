namespace trivia_client
{
    partial class personalStatsForm
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
            avgTimeToAnsHolder = new TextBox();
            gamesPlayedHolder = new TextBox();
            label3 = new Label();
            correctAnsHolder = new TextBox();
            label4 = new Label();
            bestScoreHolder = new TextBox();
            label5 = new Label();
            totalQAnsHolder = new TextBox();
            label6 = new Label();
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
            roundedButton1.TabIndex = 6;
            roundedButton1.TextColor = Color.White;
            roundedButton1.UseVisualStyleBackColor = false;
            roundedButton1.Click += roundedButton1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Monotype Corsiva", 45F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.WhiteSmoke;
            label1.Location = new Point(116, 34);
            label1.Name = "label1";
            label1.Size = new Size(655, 110);
            label1.TabIndex = 7;
            label1.Text = "My Personal Stats";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Monotype Corsiva", 19F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.WhiteSmoke;
            label2.Location = new Point(168, 500);
            label2.Name = "label2";
            label2.Size = new Size(377, 46);
            label2.TabIndex = 8;
            label2.Text = "Average Time To Answer";
            // 
            // avgTimeToAnsHolder
            // 
            avgTimeToAnsHolder.BackColor = Color.DimGray;
            avgTimeToAnsHolder.Font = new Font("David", 22F, FontStyle.Bold, GraphicsUnit.Point);
            avgTimeToAnsHolder.ForeColor = Color.Fuchsia;
            avgTimeToAnsHolder.Location = new Point(554, 500);
            avgTimeToAnsHolder.Multiline = true;
            avgTimeToAnsHolder.Name = "avgTimeToAnsHolder";
            avgTimeToAnsHolder.ReadOnly = true;
            avgTimeToAnsHolder.Size = new Size(137, 52);
            avgTimeToAnsHolder.TabIndex = 9;
            // 
            // gamesPlayedHolder
            // 
            gamesPlayedHolder.BackColor = Color.DimGray;
            gamesPlayedHolder.Font = new Font("David", 22F, FontStyle.Bold, GraphicsUnit.Point);
            gamesPlayedHolder.ForeColor = Color.Red;
            gamesPlayedHolder.Location = new Point(554, 171);
            gamesPlayedHolder.Multiline = true;
            gamesPlayedHolder.Name = "gamesPlayedHolder";
            gamesPlayedHolder.ReadOnly = true;
            gamesPlayedHolder.Size = new Size(137, 52);
            gamesPlayedHolder.TabIndex = 11;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Monotype Corsiva", 19F, FontStyle.Bold, GraphicsUnit.Point);
            label3.ForeColor = Color.WhiteSmoke;
            label3.Location = new Point(160, 171);
            label3.Name = "label3";
            label3.Size = new Size(389, 46);
            label3.TabIndex = 10;
            label3.Text = "Number Of Games Played";
            // 
            // correctAnsHolder
            // 
            correctAnsHolder.BackColor = Color.DimGray;
            correctAnsHolder.Font = new Font("David", 22F, FontStyle.Bold, GraphicsUnit.Point);
            correctAnsHolder.ForeColor = Color.LightSeaGreen;
            correctAnsHolder.Location = new Point(554, 417);
            correctAnsHolder.Multiline = true;
            correctAnsHolder.Name = "correctAnsHolder";
            correctAnsHolder.ReadOnly = true;
            correctAnsHolder.Size = new Size(137, 52);
            correctAnsHolder.TabIndex = 13;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Monotype Corsiva", 19F, FontStyle.Bold, GraphicsUnit.Point);
            label4.ForeColor = Color.WhiteSmoke;
            label4.Location = new Point(127, 417);
            label4.Name = "label4";
            label4.Size = new Size(422, 46);
            label4.TabIndex = 12;
            label4.Text = "Number Of Correct Answers";
            // 
            // bestScoreHolder
            // 
            bestScoreHolder.BackColor = Color.DimGray;
            bestScoreHolder.Font = new Font("David", 22F, FontStyle.Bold, GraphicsUnit.Point);
            bestScoreHolder.ForeColor = Color.Gold;
            bestScoreHolder.Location = new Point(554, 249);
            bestScoreHolder.Multiline = true;
            bestScoreHolder.Name = "bestScoreHolder";
            bestScoreHolder.ReadOnly = true;
            bestScoreHolder.Size = new Size(137, 52);
            bestScoreHolder.TabIndex = 15;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Monotype Corsiva", 19F, FontStyle.Bold, GraphicsUnit.Point);
            label5.ForeColor = Color.WhiteSmoke;
            label5.Location = new Point(247, 249);
            label5.Name = "label5";
            label5.Size = new Size(293, 46);
            label5.TabIndex = 14;
            label5.Text = "Best Score Achived";
            // 
            // totalQAnsHolder
            // 
            totalQAnsHolder.BackColor = Color.DimGray;
            totalQAnsHolder.Font = new Font("David", 22F, FontStyle.Bold, GraphicsUnit.Point);
            totalQAnsHolder.ForeColor = Color.YellowGreen;
            totalQAnsHolder.Location = new Point(554, 334);
            totalQAnsHolder.Multiline = true;
            totalQAnsHolder.Name = "totalQAnsHolder";
            totalQAnsHolder.ReadOnly = true;
            totalQAnsHolder.Size = new Size(137, 52);
            totalQAnsHolder.TabIndex = 17;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Monotype Corsiva", 19F, FontStyle.Bold, GraphicsUnit.Point);
            label6.ForeColor = Color.WhiteSmoke;
            label6.Location = new Point(81, 334);
            label6.Name = "label6";
            label6.Size = new Size(464, 46);
            label6.TabIndex = 16;
            label6.Text = "Number Of Questions Answerd";
            // 
            // personalStatsForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(880, 600);
            Controls.Add(totalQAnsHolder);
            Controls.Add(label6);
            Controls.Add(bestScoreHolder);
            Controls.Add(label5);
            Controls.Add(correctAnsHolder);
            Controls.Add(label4);
            Controls.Add(gamesPlayedHolder);
            Controls.Add(label3);
            Controls.Add(avgTimeToAnsHolder);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(roundedButton1);
            FormBorderStyle = FormBorderStyle.None;
            Name = "personalStatsForm";
            Text = "personalStatsForm";
            Load += personalStatsForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private designs.RoundedButton roundedButton1;
        private Label label1;
        private Label label2;
        private TextBox avgTimeToAnsHolder;
        private TextBox gamesPlayedHolder;
        private Label label3;
        private TextBox correctAnsHolder;
        private Label label4;
        private TextBox bestScoreHolder;
        private Label label5;
        private TextBox totalQAnsHolder;
        private Label label6;
    }
}