namespace trivia_client
{
    partial class CreateRoomForm
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
            label6 = new Label();
            questionTimeHolder = new TextBox();
            label5 = new Label();
            questionCountHolder = new TextBox();
            label4 = new Label();
            roomNameHolder = new TextBox();
            label3 = new Label();
            maxPlayersHolder = new TextBox();
            registerButton = new designs.RoundedButton();
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
            roundedButton1.Location = new Point(810, 23);
            roundedButton1.Name = "roundedButton1";
            roundedButton1.RightToLeft = RightToLeft.Yes;
            roundedButton1.Size = new Size(43, 42);
            roundedButton1.TabIndex = 4;
            roundedButton1.TextColor = Color.White;
            roundedButton1.UseVisualStyleBackColor = false;
            roundedButton1.Click += roundedButton1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.DimGray;
            label1.CausesValidation = false;
            label1.Font = new Font("Monotype Corsiva", 50F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.WhiteSmoke;
            label1.Location = new Point(171, 23);
            label1.Name = "label1";
            label1.Size = new Size(577, 122);
            label1.TabIndex = 5;
            label1.Text = "Create a Room";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Monotype Corsiva", 16F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.Red;
            label2.Location = new Point(299, 134);
            label2.Name = "label2";
            label2.Size = new Size(284, 39);
            label2.TabIndex = 6;
            label2.Text = "Please fill the fields...";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Monotype Corsiva", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label6.ForeColor = Color.Red;
            label6.Location = new Point(59, 350);
            label6.Name = "label6";
            label6.Size = new Size(304, 44);
            label6.TabIndex = 21;
            label6.Text = "Enter Question Time";
            // 
            // questionTimeHolder
            // 
            questionTimeHolder.BackColor = Color.Snow;
            questionTimeHolder.BorderStyle = BorderStyle.FixedSingle;
            questionTimeHolder.Font = new Font("David", 16F, FontStyle.Bold, GraphicsUnit.Point);
            questionTimeHolder.ForeColor = Color.Black;
            questionTimeHolder.Location = new Point(72, 397);
            questionTimeHolder.Name = "questionTimeHolder";
            questionTimeHolder.Size = new Size(311, 39);
            questionTimeHolder.TabIndex = 20;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Monotype Corsiva", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label5.ForeColor = Color.Red;
            label5.Location = new Point(501, 350);
            label5.Name = "label5";
            label5.Size = new Size(323, 44);
            label5.TabIndex = 19;
            label5.Text = "Enter Question Count";
            // 
            // questionCountHolder
            // 
            questionCountHolder.BackColor = Color.Snow;
            questionCountHolder.BorderStyle = BorderStyle.FixedSingle;
            questionCountHolder.Font = new Font("David", 16F, FontStyle.Bold, GraphicsUnit.Point);
            questionCountHolder.ForeColor = Color.Black;
            questionCountHolder.Location = new Point(514, 397);
            questionCountHolder.Name = "questionCountHolder";
            questionCountHolder.Size = new Size(327, 39);
            questionCountHolder.TabIndex = 18;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Monotype Corsiva", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label4.ForeColor = Color.Red;
            label4.Location = new Point(501, 223);
            label4.Name = "label4";
            label4.Size = new Size(270, 44);
            label4.TabIndex = 17;
            label4.Text = "Enter Room Name";
            // 
            // roomNameHolder
            // 
            roomNameHolder.BackColor = Color.Snow;
            roomNameHolder.BorderStyle = BorderStyle.FixedSingle;
            roomNameHolder.Font = new Font("David", 16F, FontStyle.Bold, GraphicsUnit.Point);
            roomNameHolder.ForeColor = Color.Black;
            roomNameHolder.Location = new Point(514, 270);
            roomNameHolder.Name = "roomNameHolder";
            roomNameHolder.Size = new Size(327, 39);
            roomNameHolder.TabIndex = 16;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Monotype Corsiva", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label3.ForeColor = Color.Red;
            label3.Location = new Point(59, 223);
            label3.Name = "label3";
            label3.Size = new Size(336, 44);
            label3.TabIndex = 15;
            label3.Text = "Enter The Max Players";
            // 
            // maxPlayersHolder
            // 
            maxPlayersHolder.BackColor = Color.Snow;
            maxPlayersHolder.BorderStyle = BorderStyle.FixedSingle;
            maxPlayersHolder.Font = new Font("David", 16F, FontStyle.Bold, GraphicsUnit.Point);
            maxPlayersHolder.ForeColor = Color.Black;
            maxPlayersHolder.Location = new Point(72, 270);
            maxPlayersHolder.Name = "maxPlayersHolder";
            maxPlayersHolder.Size = new Size(311, 39);
            maxPlayersHolder.TabIndex = 14;
            maxPlayersHolder.TextChanged += usernameHolder_TextChanged;
            // 
            // registerButton
            // 
            registerButton.BackColor = Color.Red;
            registerButton.BackgroundColor = Color.Red;
            registerButton.BorderColor = Color.Aquamarine;
            registerButton.BorderRadius = 15;
            registerButton.BorderSize = 0;
            registerButton.FlatAppearance.BorderSize = 0;
            registerButton.FlatStyle = FlatStyle.Flat;
            registerButton.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            registerButton.ForeColor = Color.WhiteSmoke;
            registerButton.Location = new Point(320, 504);
            registerButton.Name = "registerButton";
            registerButton.Size = new Size(231, 53);
            registerButton.TabIndex = 22;
            registerButton.Text = "Create!";
            registerButton.TextColor = Color.WhiteSmoke;
            registerButton.UseVisualStyleBackColor = false;
            registerButton.Click += registerButton_Click;
            // 
            // CreateRoomForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(880, 600);
            Controls.Add(registerButton);
            Controls.Add(label6);
            Controls.Add(questionTimeHolder);
            Controls.Add(label5);
            Controls.Add(questionCountHolder);
            Controls.Add(label4);
            Controls.Add(roomNameHolder);
            Controls.Add(label3);
            Controls.Add(maxPlayersHolder);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(roundedButton1);
            FormBorderStyle = FormBorderStyle.None;
            Name = "CreateRoomForm";
            Text = "CreateRoomForm";
            Load += CreateRoomForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private designs.RoundedButton roundedButton1;
        private Label label1;
        private Label label2;
        private Label label6;
        private TextBox questionTimeHolder;
        private Label label5;
        private TextBox questionCountHolder;
        private Label label4;
        private TextBox roomNameHolder;
        private Label label3;
        private TextBox maxPlayersHolder;
        private designs.RoundedButton registerButton;
    }
}