namespace trivia_client
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            roundedButton1 = new designs.RoundedButton();
            label1 = new Label();
            label2 = new Label();
            usernameHolder = new TextBox();
            label3 = new Label();
            passHolder = new TextBox();
            label4 = new Label();
            loginButton = new designs.RoundedButton();
            label5 = new Label();
            createButton = new designs.RoundedButton();
            showPass1 = new designs.RoundedButton();
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
            roundedButton1.Location = new Point(807, 35);
            roundedButton1.Name = "roundedButton1";
            roundedButton1.RightToLeft = RightToLeft.Yes;
            roundedButton1.Size = new Size(43, 42);
            roundedButton1.TabIndex = 1;
            roundedButton1.TextColor = Color.White;
            roundedButton1.UseVisualStyleBackColor = false;
            roundedButton1.Click += roundedButton1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Monotype Corsiva", 50F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.Red;
            label1.Location = new Point(216, 35);
            label1.Name = "label1";
            label1.Size = new Size(404, 122);
            label1.TabIndex = 2;
            label1.Text = "Welcome!";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("David", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.WhiteSmoke;
            label2.Location = new Point(338, 138);
            label2.Name = "label2";
            label2.Size = new Size(195, 35);
            label2.TabIndex = 3;
            label2.Text = "Please login";
            // 
            // usernameHolder
            // 
            usernameHolder.BackColor = Color.Snow;
            usernameHolder.BorderStyle = BorderStyle.FixedSingle;
            usernameHolder.Font = new Font("David", 16F, FontStyle.Bold, GraphicsUnit.Point);
            usernameHolder.ForeColor = Color.Black;
            usernameHolder.Location = new Point(233, 253);
            usernameHolder.Name = "usernameHolder";
            usernameHolder.Size = new Size(392, 39);
            usernameHolder.TabIndex = 4;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Monotype Corsiva", 20F, FontStyle.Bold, GraphicsUnit.Point);
            label3.ForeColor = Color.Red;
            label3.Location = new Point(216, 201);
            label3.Name = "label3";
            label3.Size = new Size(352, 49);
            label3.TabIndex = 5;
            label3.Text = "Enter Your Username";
            // 
            // passHolder
            // 
            passHolder.BackColor = Color.Snow;
            passHolder.BorderStyle = BorderStyle.FixedSingle;
            passHolder.Font = new Font("David", 16F, FontStyle.Bold, GraphicsUnit.Point);
            passHolder.ForeColor = Color.Black;
            passHolder.Location = new Point(233, 365);
            passHolder.Name = "passHolder";
            passHolder.Size = new Size(392, 39);
            passHolder.TabIndex = 6;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Monotype Corsiva", 20F, FontStyle.Bold, GraphicsUnit.Point);
            label4.ForeColor = Color.Red;
            label4.Location = new Point(216, 313);
            label4.Name = "label4";
            label4.Size = new Size(168, 49);
            label4.TabIndex = 7;
            label4.Text = "Password";
            // 
            // loginButton
            // 
            loginButton.BackColor = Color.Red;
            loginButton.BackgroundColor = Color.Red;
            loginButton.BorderColor = Color.Aquamarine;
            loginButton.BorderRadius = 15;
            loginButton.BorderSize = 0;
            loginButton.FlatAppearance.BorderSize = 0;
            loginButton.FlatStyle = FlatStyle.Flat;
            loginButton.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            loginButton.ForeColor = Color.WhiteSmoke;
            loginButton.Location = new Point(359, 428);
            loginButton.Name = "loginButton";
            loginButton.Size = new Size(174, 52);
            loginButton.TabIndex = 8;
            loginButton.Text = "Login";
            loginButton.TextColor = Color.WhiteSmoke;
            loginButton.UseVisualStyleBackColor = false;
            loginButton.Click += loginButton_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.ForeColor = Color.WhiteSmoke;
            label5.Location = new Point(277, 505);
            label5.Name = "label5";
            label5.Size = new Size(343, 25);
            label5.TabIndex = 9;
            label5.Text = "You dont have an account? Create one!";
            // 
            // createButton
            // 
            createButton.BackColor = Color.Red;
            createButton.BackgroundColor = Color.Red;
            createButton.BorderColor = Color.Aquamarine;
            createButton.BorderRadius = 15;
            createButton.BorderSize = 0;
            createButton.FlatAppearance.BorderSize = 0;
            createButton.FlatStyle = FlatStyle.Flat;
            createButton.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point);
            createButton.ForeColor = Color.WhiteSmoke;
            createButton.Location = new Point(313, 533);
            createButton.Name = "createButton";
            createButton.Size = new Size(267, 39);
            createButton.TabIndex = 10;
            createButton.Text = "Create an account";
            createButton.TextColor = Color.WhiteSmoke;
            createButton.UseVisualStyleBackColor = false;
            createButton.Click += createButton_Click;
            // 
            // showPass1
            // 
            showPass1.BackColor = Color.Red;
            showPass1.BackgroundColor = Color.Red;
            showPass1.BorderColor = Color.Aquamarine;
            showPass1.BorderRadius = 15;
            showPass1.BorderSize = 0;
            showPass1.FlatAppearance.BorderSize = 0;
            showPass1.FlatStyle = FlatStyle.Flat;
            showPass1.ForeColor = Color.WhiteSmoke;
            showPass1.Location = new Point(631, 361);
            showPass1.Name = "showPass1";
            showPass1.Size = new Size(121, 45);
            showPass1.TabIndex = 11;
            showPass1.Text = "'\\uU+1F441'";
            showPass1.TextColor = Color.WhiteSmoke;
            showPass1.UseVisualStyleBackColor = true;
            showPass1.Click += roundedButton2_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(11F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(880, 600);
            Controls.Add(showPass1);
            Controls.Add(createButton);
            Controls.Add(label5);
            Controls.Add(loginButton);
            Controls.Add(label4);
            Controls.Add(passHolder);
            Controls.Add(label3);
            Controls.Add(usernameHolder);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(roundedButton1);
            Font = new Font("Segoe UI", 9F, FontStyle.Bold, GraphicsUnit.Point);
            ForeColor = Color.Transparent;
            FormBorderStyle = FormBorderStyle.None;
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "LoginForm";
            TransparencyKey = Color.Transparent;
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private designs.RoundedButton roundedButton1;
        private Label label1;
        private Label label2;
        private TextBox usernameHolder;
        private Label label3;
        private TextBox passHolder;
        private Label label4;
        private designs.RoundedButton loginButton;
        private Label label5;
        private designs.RoundedButton createButton;
        private designs.RoundedButton showPass1;
    }
}