namespace trivia_client
{
    partial class EndGameForm
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
            panel1 = new Panel();
            personalScoreHolder = new Label();
            label2 = new Label();
            exitButtton = new designs.RoundedButton();
            panel2 = new Panel();
            panel3 = new Panel();
            panel4 = new Panel();
            label1 = new Label();
            place2holder = new TextBox();
            place1holder = new TextBox();
            place3holder = new TextBox();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // panel1
            // 
            panel1.BackColor = Color.Gray;
            panel1.Controls.Add(exitButtton);
            panel1.Controls.Add(personalScoreHolder);
            panel1.Controls.Add(label2);
            panel1.Location = new Point(-12, 510);
            panel1.Name = "panel1";
            panel1.Size = new Size(899, 101);
            panel1.TabIndex = 0;
            // 
            // personalScoreHolder
            // 
            personalScoreHolder.AutoSize = true;
            personalScoreHolder.BackColor = Color.DimGray;
            personalScoreHolder.Font = new Font("David", 22F, FontStyle.Bold, GraphicsUnit.Point);
            personalScoreHolder.ForeColor = Color.WhiteSmoke;
            personalScoreHolder.Location = new Point(239, 26);
            personalScoreHolder.Name = "personalScoreHolder";
            personalScoreHolder.Size = new Size(190, 43);
            personalScoreHolder.TabIndex = 5;
            personalScoreHolder.Text = "123456789";
            personalScoreHolder.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("David", 20F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.WhiteSmoke;
            label2.Location = new Point(24, 26);
            label2.Name = "label2";
            label2.Size = new Size(220, 39);
            label2.TabIndex = 5;
            label2.Text = "Your score:";
            // 
            // exitButtton
            // 
            exitButtton.BackColor = Color.Red;
            exitButtton.BackgroundColor = Color.Red;
            exitButtton.BorderColor = Color.Aquamarine;
            exitButtton.BorderRadius = 15;
            exitButtton.BorderSize = 0;
            exitButtton.FlatAppearance.BorderSize = 0;
            exitButtton.FlatStyle = FlatStyle.Flat;
            exitButtton.Font = new Font("David", 15F, FontStyle.Bold, GraphicsUnit.Point);
            exitButtton.ForeColor = Color.WhiteSmoke;
            exitButtton.Location = new Point(624, 20);
            exitButtton.Name = "exitButtton";
            exitButtton.Size = new Size(256, 55);
            exitButtton.TabIndex = 12;
            exitButtton.Text = "Back to menu";
            exitButtton.TextColor = Color.WhiteSmoke;
            exitButtton.UseVisualStyleBackColor = false;
            exitButtton.Click += exitButtton_Click;
            // 
            // panel2
            // 
            panel2.BackColor = Color.Chocolate;
            panel2.ForeColor = SystemColors.ActiveBorder;
            panel2.Location = new Point(650, 358);
            panel2.Name = "panel2";
            panel2.Size = new Size(134, 155);
            panel2.TabIndex = 1;
            // 
            // panel3
            // 
            panel3.BackColor = Color.Silver;
            panel3.ForeColor = SystemColors.ActiveBorder;
            panel3.Location = new Point(106, 276);
            panel3.Name = "panel3";
            panel3.Size = new Size(153, 237);
            panel3.TabIndex = 2;
            // 
            // panel4
            // 
            panel4.BackColor = Color.Gold;
            panel4.ForeColor = SystemColors.ActiveBorder;
            panel4.Location = new Point(379, 173);
            panel4.Name = "panel4";
            panel4.Size = new Size(160, 340);
            panel4.TabIndex = 2;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("David", 40F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.WhiteSmoke;
            label1.Location = new Point(205, 9);
            label1.Name = "label1";
            label1.Size = new Size(498, 79);
            label1.TabIndex = 4;
            label1.Text = "Game scores!";
            // 
            // place2holder
            // 
            place2holder.BackColor = Color.DimGray;
            place2holder.BorderStyle = BorderStyle.None;
            place2holder.Font = new Font("David", 14F, FontStyle.Bold, GraphicsUnit.Point);
            place2holder.ForeColor = Color.LavenderBlush;
            place2holder.Location = new Point(-2, 242);
            place2holder.Name = "place2holder";
            place2holder.Size = new Size(364, 28);
            place2holder.TabIndex = 5;
            place2holder.Text = "username-10000";
            place2holder.TextAlign = HorizontalAlignment.Center;
            // 
            // place1holder
            // 
            place1holder.BackColor = Color.DimGray;
            place1holder.BorderStyle = BorderStyle.None;
            place1holder.Font = new Font("David", 14F, FontStyle.Bold, GraphicsUnit.Point);
            place1holder.ForeColor = Color.LavenderBlush;
            place1holder.Location = new Point(277, 139);
            place1holder.Name = "place1holder";
            place1holder.Size = new Size(364, 28);
            place1holder.TabIndex = 6;
            place1holder.Text = "username-10000";
            place1holder.TextAlign = HorizontalAlignment.Center;
            // 
            // place3holder
            // 
            place3holder.BackColor = Color.DimGray;
            place3holder.BorderStyle = BorderStyle.None;
            place3holder.Font = new Font("David", 14F, FontStyle.Bold, GraphicsUnit.Point);
            place3holder.ForeColor = Color.LavenderBlush;
            place3holder.Location = new Point(545, 324);
            place3holder.Name = "place3holder";
            place3holder.Size = new Size(342, 28);
            place3holder.TabIndex = 7;
            place3holder.Text = "username-10000";
            place3holder.TextAlign = HorizontalAlignment.Center;
            // 
            // EndGameForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(880, 600);
            Controls.Add(place3holder);
            Controls.Add(place1holder);
            Controls.Add(place2holder);
            Controls.Add(label1);
            Controls.Add(panel3);
            Controls.Add(panel4);
            Controls.Add(panel2);
            Controls.Add(panel1);
            FormBorderStyle = FormBorderStyle.None;
            Name = "EndGameForm";
            Text = "EndGameForm";
            Load += EndGameForm_Load;
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Panel panel1;
        private Panel panel2;
        private Panel panel3;
        private Panel panel4;
        private Label label2;
        private Label label1;
        private Label personalScoreHolder;
        private designs.RoundedButton exitButtton;
        private TextBox place2holder;
        private TextBox place1holder;
        private TextBox place3holder;
    }
}