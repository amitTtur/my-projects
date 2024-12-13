namespace trivia_client
{
    partial class topScorersForm
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
            top1Holder = new TextBox();
            label1 = new Label();
            top2Holder = new TextBox();
            top4Holder = new TextBox();
            top5Holder = new TextBox();
            top3Holder = new TextBox();
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
            roundedButton1.TabIndex = 7;
            roundedButton1.TextColor = Color.White;
            roundedButton1.UseVisualStyleBackColor = false;
            roundedButton1.Click += roundedButton1_Click;
            // 
            // top1Holder
            // 
            top1Holder.BackColor = Color.DimGray;
            top1Holder.Font = new Font("David", 30F, FontStyle.Bold, GraphicsUnit.Point);
            top1Holder.ForeColor = Color.Gold;
            top1Holder.Location = new Point(177, 213);
            top1Holder.Multiline = true;
            top1Holder.Name = "top1Holder";
            top1Holder.ReadOnly = true;
            top1Holder.Size = new Size(519, 70);
            top1Holder.TabIndex = 22;
            top1Holder.Text = "NONE";
            top1Holder.TextAlign = HorizontalAlignment.Center;
            top1Holder.TextChanged += top1Holder_TextChanged;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Monotype Corsiva", 60F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.WhiteSmoke;
            label1.Location = new Point(177, 40);
            label1.Name = "label1";
            label1.Size = new Size(518, 147);
            label1.TabIndex = 18;
            label1.Text = "Top Scores";
            // 
            // top2Holder
            // 
            top2Holder.BackColor = Color.DimGray;
            top2Holder.Font = new Font("David", 22F, FontStyle.Bold, GraphicsUnit.Point);
            top2Holder.ForeColor = Color.LightGray;
            top2Holder.Location = new Point(218, 308);
            top2Holder.Multiline = true;
            top2Holder.Name = "top2Holder";
            top2Holder.ReadOnly = true;
            top2Holder.Size = new Size(435, 53);
            top2Holder.TabIndex = 23;
            top2Holder.Text = "NONE";
            top2Holder.TextAlign = HorizontalAlignment.Center;
            // 
            // top4Holder
            // 
            top4Holder.BackColor = Color.DimGray;
            top4Holder.Font = new Font("David", 16F, FontStyle.Bold, GraphicsUnit.Point);
            top4Holder.ForeColor = Color.SaddleBrown;
            top4Holder.Location = new Point(277, 458);
            top4Holder.Multiline = true;
            top4Holder.Name = "top4Holder";
            top4Holder.ReadOnly = true;
            top4Holder.Size = new Size(325, 41);
            top4Holder.TabIndex = 24;
            top4Holder.Text = "NONE";
            top4Holder.TextAlign = HorizontalAlignment.Center;
            // 
            // top5Holder
            // 
            top5Holder.BackColor = Color.DimGray;
            top5Holder.Font = new Font("David", 12F, FontStyle.Bold, GraphicsUnit.Point);
            top5Holder.ForeColor = Color.DarkRed;
            top5Holder.Location = new Point(316, 521);
            top5Holder.Multiline = true;
            top5Holder.Name = "top5Holder";
            top5Holder.ReadOnly = true;
            top5Holder.Size = new Size(252, 33);
            top5Holder.TabIndex = 25;
            top5Holder.Text = "NONE";
            top5Holder.TextAlign = HorizontalAlignment.Center;
            // 
            // top3Holder
            // 
            top3Holder.BackColor = Color.DimGray;
            top3Holder.Font = new Font("David", 19F, FontStyle.Bold, GraphicsUnit.Point);
            top3Holder.ForeColor = Color.Peru;
            top3Holder.Location = new Point(248, 386);
            top3Holder.Multiline = true;
            top3Holder.Name = "top3Holder";
            top3Holder.ReadOnly = true;
            top3Holder.Size = new Size(377, 47);
            top3Holder.TabIndex = 26;
            top3Holder.Text = "NONE";
            top3Holder.TextAlign = HorizontalAlignment.Center;
            // 
            // topScorersForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(880, 600);
            Controls.Add(top3Holder);
            Controls.Add(top5Holder);
            Controls.Add(top4Holder);
            Controls.Add(top2Holder);
            Controls.Add(top1Holder);
            Controls.Add(label1);
            Controls.Add(roundedButton1);
            FormBorderStyle = FormBorderStyle.None;
            Name = "topScorersForm";
            Text = "topScorersForm";
            Load += topScorersForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private designs.RoundedButton roundedButton1;
        private TextBox top1Holder;
        private Label label1;
        private TextBox top2Holder;
        private TextBox top4Holder;
        private TextBox top5Holder;
        private TextBox top3Holder;
    }
}