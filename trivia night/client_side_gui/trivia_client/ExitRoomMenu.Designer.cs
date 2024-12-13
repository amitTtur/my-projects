namespace trivia_client
{
    partial class ExitRoomMenu
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
            roundedButton2 = new designs.RoundedButton();
            label1 = new Label();
            roundedButton1 = new designs.RoundedButton();
            SuspendLayout();
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
            roundedButton2.Location = new Point(276, 135);
            roundedButton2.Name = "roundedButton2";
            roundedButton2.Size = new Size(172, 50);
            roundedButton2.TabIndex = 6;
            roundedButton2.Text = "Cancel";
            roundedButton2.TextColor = Color.White;
            roundedButton2.UseVisualStyleBackColor = false;
            roundedButton2.Click += roundedButton2_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Monotype Corsiva", 18F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label1.ForeColor = Color.WhiteSmoke;
            label1.Location = new Point(29, 46);
            label1.Name = "label1";
            label1.Size = new Size(461, 44);
            label1.TabIndex = 4;
            label1.Text = "Do you Want to Exit The room?";
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
            roundedButton1.Location = new Point(70, 135);
            roundedButton1.Name = "roundedButton1";
            roundedButton1.Size = new Size(172, 50);
            roundedButton1.TabIndex = 7;
            roundedButton1.Text = "Exit";
            roundedButton1.TextColor = Color.White;
            roundedButton1.UseVisualStyleBackColor = false;
            roundedButton1.Click += roundedButton1_Click;
            // 
            // ExitRoomMenu
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(502, 227);
            Controls.Add(roundedButton1);
            Controls.Add(roundedButton2);
            Controls.Add(label1);
            FormBorderStyle = FormBorderStyle.None;
            Name = "ExitRoomMenu";
            Text = "ExitRoomMenu";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private designs.RoundedButton roundedButton2;
        private Label label1;
        private designs.RoundedButton roundedButton1;
    }
}