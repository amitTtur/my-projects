namespace trivia_client
{
    partial class SignUpForm
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
            usernameHolder = new TextBox();
            label4 = new Label();
            emailHolder = new TextBox();
            label5 = new Label();
            confirmPassHolder = new TextBox();
            label6 = new Label();
            passHolder = new TextBox();
            registerButton = new designs.RoundedButton();
            showPass1 = new designs.RoundedButton();
            showPass2 = new designs.RoundedButton();
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
            roundedButton1.Location = new Point(801, 36);
            roundedButton1.Name = "roundedButton1";
            roundedButton1.RightToLeft = RightToLeft.Yes;
            roundedButton1.Size = new Size(43, 42);
            roundedButton1.TabIndex = 2;
            roundedButton1.TextColor = Color.White;
            roundedButton1.UseVisualStyleBackColor = false;
            roundedButton1.Click += roundedButton1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Monotype Corsiva", 40F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.Red;
            label1.Location = new Point(144, 49);
            label1.Name = "label1";
            label1.Size = new Size(589, 97);
            label1.TabIndex = 3;
            label1.Text = "Create an account!";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("David", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label2.ForeColor = Color.WhiteSmoke;
            label2.Location = new Point(274, 146);
            label2.Name = "label2";
            label2.Size = new Size(337, 35);
            label2.TabIndex = 4;
            label2.Text = "Please fill the fields...";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Monotype Corsiva", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label3.ForeColor = Color.Red;
            label3.Location = new Point(49, 221);
            label3.Name = "label3";
            label3.Size = new Size(301, 44);
            label3.TabIndex = 7;
            label3.Text = "Enter The Username";
            // 
            // usernameHolder
            // 
            usernameHolder.BackColor = Color.Snow;
            usernameHolder.BorderStyle = BorderStyle.FixedSingle;
            usernameHolder.Font = new Font("David", 16F, FontStyle.Bold, GraphicsUnit.Point);
            usernameHolder.ForeColor = Color.Black;
            usernameHolder.Location = new Point(62, 268);
            usernameHolder.Name = "usernameHolder";
            usernameHolder.Size = new Size(324, 39);
            usernameHolder.TabIndex = 6;
            usernameHolder.TextChanged += usernameHolder_TextChanged;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Monotype Corsiva", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label4.ForeColor = Color.Red;
            label4.Location = new Point(49, 365);
            label4.Name = "label4";
            label4.Size = new Size(247, 44);
            label4.TabIndex = 9;
            label4.Text = "Enter The Email";
            // 
            // emailHolder
            // 
            emailHolder.BackColor = Color.Snow;
            emailHolder.BorderStyle = BorderStyle.FixedSingle;
            emailHolder.Font = new Font("David", 16F, FontStyle.Bold, GraphicsUnit.Point);
            emailHolder.ForeColor = Color.Black;
            emailHolder.Location = new Point(59, 412);
            emailHolder.Name = "emailHolder";
            emailHolder.Size = new Size(327, 39);
            emailHolder.TabIndex = 8;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Monotype Corsiva", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label5.ForeColor = Color.Red;
            label5.Location = new Point(447, 365);
            label5.Name = "label5";
            label5.Size = new Size(270, 44);
            label5.TabIndex = 11;
            label5.Text = "Confirm Password";
            // 
            // confirmPassHolder
            // 
            confirmPassHolder.BackColor = Color.Snow;
            confirmPassHolder.BorderStyle = BorderStyle.FixedSingle;
            confirmPassHolder.Font = new Font("David", 16F, FontStyle.Bold, GraphicsUnit.Point);
            confirmPassHolder.ForeColor = Color.Black;
            confirmPassHolder.Location = new Point(460, 412);
            confirmPassHolder.Name = "confirmPassHolder";
            confirmPassHolder.Size = new Size(311, 39);
            confirmPassHolder.TabIndex = 10;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Monotype Corsiva", 18F, FontStyle.Bold, GraphicsUnit.Point);
            label6.ForeColor = Color.Red;
            label6.Location = new Point(447, 221);
            label6.Name = "label6";
            label6.Size = new Size(296, 44);
            label6.TabIndex = 13;
            label6.Text = "Enter The Password";
            // 
            // passHolder
            // 
            passHolder.BackColor = Color.Snow;
            passHolder.BorderStyle = BorderStyle.FixedSingle;
            passHolder.Font = new Font("David", 16F, FontStyle.Bold, GraphicsUnit.Point);
            passHolder.ForeColor = Color.Black;
            passHolder.Location = new Point(460, 268);
            passHolder.Name = "passHolder";
            passHolder.Size = new Size(311, 39);
            passHolder.TabIndex = 12;
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
            registerButton.Location = new Point(323, 501);
            registerButton.Name = "registerButton";
            registerButton.Size = new Size(231, 53);
            registerButton.TabIndex = 14;
            registerButton.Text = "Register!";
            registerButton.TextColor = Color.WhiteSmoke;
            registerButton.UseVisualStyleBackColor = false;
            registerButton.Click += registerButton_Click;
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
            showPass1.Location = new Point(777, 264);
            showPass1.Name = "showPass1";
            showPass1.Size = new Size(75, 45);
            showPass1.TabIndex = 15;
            showPass1.Text = "'\\uU+1F441'";
            showPass1.TextColor = Color.WhiteSmoke;
            showPass1.UseVisualStyleBackColor = true;
            showPass1.Click += showPass1_Click;
            // 
            // showPass2
            // 
            showPass2.BackColor = Color.Red;
            showPass2.BackgroundColor = Color.Red;
            showPass2.BorderColor = Color.Aquamarine;
            showPass2.BorderRadius = 15;
            showPass2.BorderSize = 0;
            showPass2.FlatAppearance.BorderSize = 0;
            showPass2.FlatStyle = FlatStyle.Flat;
            showPass2.ForeColor = Color.WhiteSmoke;
            showPass2.Location = new Point(777, 406);
            showPass2.Name = "showPass2";
            showPass2.Size = new Size(75, 45);
            showPass2.TabIndex = 16;
            showPass2.Text = "'\\uU+1F441'";
            showPass2.TextColor = Color.WhiteSmoke;
            showPass2.UseVisualStyleBackColor = true;
            showPass2.Click += showPass2_Click;
            // 
            // SignUpForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(880, 600);
            Controls.Add(showPass2);
            Controls.Add(showPass1);
            Controls.Add(registerButton);
            Controls.Add(label6);
            Controls.Add(passHolder);
            Controls.Add(label5);
            Controls.Add(confirmPassHolder);
            Controls.Add(label4);
            Controls.Add(emailHolder);
            Controls.Add(label3);
            Controls.Add(usernameHolder);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(roundedButton1);
            FormBorderStyle = FormBorderStyle.None;
            Name = "SignUpForm";
            Text = "SignUpForm";
            Load += SignUpForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private designs.RoundedButton roundedButton1;
        private Label label1;
        private Label label2;
        private Label label3;
        private TextBox usernameHolder;
        private Label label4;
        private TextBox emailHolder;
        private Label label5;
        private TextBox confirmPassHolder;
        private Label label6;
        private TextBox passHolder;
        private designs.RoundedButton registerButton;
        private designs.RoundedButton showPass1;
        private designs.RoundedButton showPass2;
    }
}