namespace trivia_client
{
    partial class ShowErrorForm
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
            errorTextBox = new TextBox();
            panel1 = new Panel();
            panel2 = new Panel();
            panel3 = new Panel();
            panel4 = new Panel();
            panel5 = new Panel();
            panel6 = new Panel();
            panel7 = new Panel();
            panel8 = new Panel();
            panel9 = new Panel();
            panel1.SuspendLayout();
            panel2.SuspendLayout();
            panel3.SuspendLayout();
            panel5.SuspendLayout();
            panel7.SuspendLayout();
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
            roundedButton1.Font = new Font("Segoe UI", 11F, FontStyle.Bold, GraphicsUnit.Point);
            roundedButton1.ForeColor = Color.White;
            roundedButton1.Location = new Point(184, 197);
            roundedButton1.Name = "roundedButton1";
            roundedButton1.RightToLeft = RightToLeft.Yes;
            roundedButton1.Size = new Size(215, 38);
            roundedButton1.TabIndex = 2;
            roundedButton1.Text = "Continue";
            roundedButton1.TextColor = Color.White;
            roundedButton1.TextImageRelation = TextImageRelation.TextAboveImage;
            roundedButton1.UseVisualStyleBackColor = false;
            roundedButton1.Click += roundedButton1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("David", 22F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.White;
            label1.Location = new Point(115, 26);
            label1.Name = "label1";
            label1.Size = new Size(376, 43);
            label1.TabIndex = 3;
            label1.Text = "An Error occurred";
            // 
            // errorTextBox
            // 
            errorTextBox.BackColor = Color.Gray;
            errorTextBox.BorderStyle = BorderStyle.FixedSingle;
            errorTextBox.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            errorTextBox.ForeColor = Color.WhiteSmoke;
            errorTextBox.Location = new Point(60, 84);
            errorTextBox.Multiline = true;
            errorTextBox.Name = "errorTextBox";
            errorTextBox.ReadOnly = true;
            errorTextBox.Size = new Size(491, 97);
            errorTextBox.TabIndex = 4;
            errorTextBox.TabStop = false;
            errorTextBox.Text = "Unknown Error...";
            errorTextBox.TextAlign = HorizontalAlignment.Center;
            // 
            // panel1
            // 
            panel1.BackColor = Color.Red;
            panel1.Controls.Add(panel2);
            panel1.Location = new Point(-2, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(598, 5);
            panel1.TabIndex = 5;
            // 
            // panel2
            // 
            panel2.BackColor = Color.Red;
            panel2.Controls.Add(panel4);
            panel2.Location = new Point(0, 0);
            panel2.Name = "panel2";
            panel2.Size = new Size(598, 5);
            panel2.TabIndex = 6;
            // 
            // panel3
            // 
            panel3.BackColor = Color.Red;
            panel3.Controls.Add(panel5);
            panel3.Location = new Point(-2, 241);
            panel3.Name = "panel3";
            panel3.Size = new Size(598, 5);
            panel3.TabIndex = 7;
            // 
            // panel4
            // 
            panel4.BackColor = Color.Red;
            panel4.Location = new Point(3, 0);
            panel4.Name = "panel4";
            panel4.Size = new Size(5, 243);
            panel4.TabIndex = 8;
            // 
            // panel5
            // 
            panel5.BackColor = Color.Red;
            panel5.Controls.Add(panel6);
            panel5.Location = new Point(0, 0);
            panel5.Name = "panel5";
            panel5.Size = new Size(598, 5);
            panel5.TabIndex = 8;
            // 
            // panel6
            // 
            panel6.BackColor = Color.Red;
            panel6.Location = new Point(0, 0);
            panel6.Name = "panel6";
            panel6.Size = new Size(598, 5);
            panel6.TabIndex = 9;
            // 
            // panel7
            // 
            panel7.BackColor = Color.Red;
            panel7.Controls.Add(panel8);
            panel7.Location = new Point(-2, -1);
            panel7.Name = "panel7";
            panel7.Size = new Size(8, 247);
            panel7.TabIndex = 9;
            // 
            // panel8
            // 
            panel8.BackColor = Color.Red;
            panel8.Location = new Point(0, 0);
            panel8.Name = "panel8";
            panel8.Size = new Size(8, 247);
            panel8.TabIndex = 10;
            // 
            // panel9
            // 
            panel9.BackColor = Color.Red;
            panel9.Location = new Point(588, 3);
            panel9.Name = "panel9";
            panel9.Size = new Size(8, 247);
            panel9.TabIndex = 10;
            // 
            // ShowErrorForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.Gray;
            ClientSize = new Size(594, 247);
            Controls.Add(panel9);
            Controls.Add(panel7);
            Controls.Add(panel3);
            Controls.Add(panel1);
            Controls.Add(errorTextBox);
            Controls.Add(label1);
            Controls.Add(roundedButton1);
            FormBorderStyle = FormBorderStyle.None;
            Name = "ShowErrorForm";
            Text = "ShowErrorForm";
            Load += ShowErrorForm_Load;
            panel1.ResumeLayout(false);
            panel2.ResumeLayout(false);
            panel3.ResumeLayout(false);
            panel5.ResumeLayout(false);
            panel7.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private designs.RoundedButton roundedButton1;
        private Label label1;
        private TextBox errorTextBox;
        private Panel panel1;
        private Panel panel2;
        private Panel panel4;
        private Panel panel3;
        private Panel panel5;
        private Panel panel6;
        private Panel panel7;
        private Panel panel8;
        private Panel panel9;
    }
}