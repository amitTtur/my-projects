namespace trivia_client
{
    partial class LogoutOrExitForm
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
            label1 = new Label();
            roundedButton1 = new designs.RoundedButton();
            label2 = new Label();
            roundedButton2 = new designs.RoundedButton();
            roundedButton3 = new designs.RoundedButton();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Monotype Corsiva", 20F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.WhiteSmoke;
            label1.Location = new Point(45, 97);
            label1.Name = "label1";
            label1.Size = new Size(627, 49);
            label1.TabIndex = 0;
            label1.Text = "Do you want to exit the app or Logout?";
            // 
            // roundedButton1
            // 
            roundedButton1.BackColor = Color.Red;
            roundedButton1.BackgroundColor = Color.Red;
            roundedButton1.BorderColor = Color.Aquamarine;
            roundedButton1.BorderRadius = 15;
            roundedButton1.BorderSize = 0;
            roundedButton1.FlatAppearance.BorderSize = 0;
            roundedButton1.FlatStyle = FlatStyle.Flat;
            roundedButton1.Font = new Font("David", 15F, FontStyle.Bold, GraphicsUnit.Point);
            roundedButton1.ForeColor = Color.White;
            roundedButton1.Location = new Point(27, 190);
            roundedButton1.Name = "roundedButton1";
            roundedButton1.Size = new Size(209, 64);
            roundedButton1.TabIndex = 1;
            roundedButton1.Text = "EXIT";
            roundedButton1.TextColor = Color.White;
            roundedButton1.UseVisualStyleBackColor = false;
            roundedButton1.Click += roundedButton1_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("David", 40F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.Red;
            label2.Location = new Point(207, 29);
            label2.Name = "label2";
            label2.Size = new Size(296, 79);
            label2.TabIndex = 2;
            label2.Text = "Wait!!!";
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
            roundedButton2.Font = new Font("David", 15F, FontStyle.Bold, GraphicsUnit.Point);
            roundedButton2.ForeColor = Color.White;
            roundedButton2.Location = new Point(242, 190);
            roundedButton2.Name = "roundedButton2";
            roundedButton2.Size = new Size(209, 64);
            roundedButton2.TabIndex = 3;
            roundedButton2.Text = "LOGOUT";
            roundedButton2.TextColor = Color.White;
            roundedButton2.UseVisualStyleBackColor = false;
            roundedButton2.Click += roundedButton2_Click;
            // 
            // roundedButton3
            // 
            roundedButton3.BackColor = Color.Red;
            roundedButton3.BackgroundColor = Color.Red;
            roundedButton3.BorderColor = Color.Aquamarine;
            roundedButton3.BorderRadius = 15;
            roundedButton3.BorderSize = 0;
            roundedButton3.FlatAppearance.BorderSize = 0;
            roundedButton3.FlatStyle = FlatStyle.Flat;
            roundedButton3.Font = new Font("David", 15F, FontStyle.Bold, GraphicsUnit.Point);
            roundedButton3.ForeColor = Color.White;
            roundedButton3.Location = new Point(463, 190);
            roundedButton3.Name = "roundedButton3";
            roundedButton3.Size = new Size(209, 64);
            roundedButton3.TabIndex = 4;
            roundedButton3.Text = "CANCEL";
            roundedButton3.TextColor = Color.White;
            roundedButton3.UseVisualStyleBackColor = false;
            roundedButton3.Click += roundedButton3_Click;
            // 
            // LogoutOrExitForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(701, 305);
            Controls.Add(roundedButton3);
            Controls.Add(roundedButton2);
            Controls.Add(label2);
            Controls.Add(roundedButton1);
            Controls.Add(label1);
            FormBorderStyle = FormBorderStyle.None;
            Name = "LogoutOrExitForm";
            Text = "LogoutOrExitForm";
            Load += LogoutOrExitForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private designs.RoundedButton roundedButton1;
        private Label label2;
        private designs.RoundedButton roundedButton2;
        private designs.RoundedButton roundedButton3;
    }
}