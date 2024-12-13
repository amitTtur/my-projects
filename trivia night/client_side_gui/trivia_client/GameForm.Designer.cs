namespace trivia_client
{
    partial class GameForm
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
            GameCountDownTextSaver = new Label();
            GameCountDown = new Label();
            GameCountDownTimer = new Label();
            aHolder2 = new designs.RoundedButton();
            aHolder4 = new designs.RoundedButton();
            aHolder1 = new designs.RoundedButton();
            aHolder3 = new designs.RoundedButton();
            timerBar = new ProgressBar();
            label1 = new Label();
            timeShowText = new Label();
            questionHolder = new TextBox();
            WaitTextHolder = new Label();
            waitToggleHolder = new Label();
            SuspendLayout();
            // 
            // GameCountDownTextSaver
            // 
            GameCountDownTextSaver.AutoSize = true;
            GameCountDownTextSaver.Font = new Font("David", 42F, FontStyle.Bold, GraphicsUnit.Point);
            GameCountDownTextSaver.ForeColor = Color.WhiteSmoke;
            GameCountDownTextSaver.Location = new Point(93, 205);
            GameCountDownTextSaver.Name = "GameCountDownTextSaver";
            GameCountDownTextSaver.Size = new Size(720, 83);
            GameCountDownTextSaver.TabIndex = 0;
            GameCountDownTextSaver.Text = "Game Starting in...";
            GameCountDownTextSaver.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // GameCountDown
            // 
            GameCountDown.AutoSize = true;
            GameCountDown.Font = new Font("David", 28F, FontStyle.Bold, GraphicsUnit.Point);
            GameCountDown.ForeColor = Color.WhiteSmoke;
            GameCountDown.Location = new Point(158, 198);
            GameCountDown.Name = "GameCountDown";
            GameCountDown.Size = new Size(0, 55);
            GameCountDown.TabIndex = 1;
            GameCountDown.Visible = false;
            // 
            // GameCountDownTimer
            // 
            GameCountDownTimer.AutoSize = true;
            GameCountDownTimer.Font = new Font("David", 35F, FontStyle.Bold, GraphicsUnit.Point);
            GameCountDownTimer.ForeColor = Color.WhiteSmoke;
            GameCountDownTimer.Location = new Point(423, 288);
            GameCountDownTimer.Name = "GameCountDownTimer";
            GameCountDownTimer.Size = new Size(60, 68);
            GameCountDownTimer.TabIndex = 2;
            GameCountDownTimer.Text = "0";
            // 
            // aHolder2
            // 
            aHolder2.BackColor = Color.WhiteSmoke;
            aHolder2.BackgroundColor = Color.WhiteSmoke;
            aHolder2.BorderColor = Color.Aquamarine;
            aHolder2.BorderRadius = 15;
            aHolder2.BorderSize = 0;
            aHolder2.FlatAppearance.BorderSize = 0;
            aHolder2.FlatStyle = FlatStyle.Flat;
            aHolder2.Font = new Font("David", 15F, FontStyle.Bold, GraphicsUnit.Point);
            aHolder2.ForeColor = Color.Red;
            aHolder2.Location = new Point(472, 402);
            aHolder2.Name = "aHolder2";
            aHolder2.Size = new Size(385, 79);
            aHolder2.TabIndex = 13;
            aHolder2.Text = "ans";
            aHolder2.TextColor = Color.Red;
            aHolder2.UseVisualStyleBackColor = false;
            aHolder2.Visible = false;
            aHolder2.Click += aHolder2_Click;
            // 
            // aHolder4
            // 
            aHolder4.BackColor = Color.WhiteSmoke;
            aHolder4.BackgroundColor = Color.WhiteSmoke;
            aHolder4.BorderColor = Color.Aquamarine;
            aHolder4.BorderRadius = 15;
            aHolder4.BorderSize = 0;
            aHolder4.FlatAppearance.BorderSize = 0;
            aHolder4.FlatStyle = FlatStyle.Flat;
            aHolder4.Font = new Font("David", 15F, FontStyle.Bold, GraphicsUnit.Point);
            aHolder4.ForeColor = Color.Red;
            aHolder4.Location = new Point(32, 402);
            aHolder4.Name = "aHolder4";
            aHolder4.Size = new Size(385, 79);
            aHolder4.TabIndex = 12;
            aHolder4.Text = "ans";
            aHolder4.TextColor = Color.Red;
            aHolder4.UseVisualStyleBackColor = false;
            aHolder4.Visible = false;
            aHolder4.Click += roundedButton4_Click;
            // 
            // aHolder1
            // 
            aHolder1.BackColor = Color.WhiteSmoke;
            aHolder1.BackgroundColor = Color.WhiteSmoke;
            aHolder1.BorderColor = Color.Aquamarine;
            aHolder1.BorderRadius = 15;
            aHolder1.BorderSize = 0;
            aHolder1.FlatAppearance.BorderSize = 0;
            aHolder1.FlatStyle = FlatStyle.Flat;
            aHolder1.Font = new Font("David", 15F, FontStyle.Bold, GraphicsUnit.Point);
            aHolder1.ForeColor = Color.Red;
            aHolder1.Location = new Point(472, 283);
            aHolder1.Name = "aHolder1";
            aHolder1.Size = new Size(385, 79);
            aHolder1.TabIndex = 11;
            aHolder1.Text = "ans";
            aHolder1.TextColor = Color.Red;
            aHolder1.UseVisualStyleBackColor = false;
            aHolder1.Visible = false;
            aHolder1.Click += aHolder1_Click;
            // 
            // aHolder3
            // 
            aHolder3.BackColor = Color.WhiteSmoke;
            aHolder3.BackgroundColor = Color.WhiteSmoke;
            aHolder3.BorderColor = Color.Aquamarine;
            aHolder3.BorderRadius = 15;
            aHolder3.BorderSize = 0;
            aHolder3.FlatAppearance.BorderSize = 0;
            aHolder3.FlatStyle = FlatStyle.Flat;
            aHolder3.Font = new Font("David", 15F, FontStyle.Bold, GraphicsUnit.Point);
            aHolder3.ForeColor = Color.Red;
            aHolder3.Location = new Point(32, 283);
            aHolder3.Name = "aHolder3";
            aHolder3.Size = new Size(385, 79);
            aHolder3.TabIndex = 10;
            aHolder3.Text = "ans";
            aHolder3.TextColor = Color.Red;
            aHolder3.UseVisualStyleBackColor = false;
            aHolder3.Visible = false;
            aHolder3.Click += aHolder3_Click;
            // 
            // timerBar
            // 
            timerBar.ForeColor = Color.Red;
            timerBar.Location = new Point(96, 79);
            timerBar.Name = "timerBar";
            timerBar.Size = new Size(743, 40);
            timerBar.TabIndex = 14;
            timerBar.Value = 4;
            timerBar.Visible = false;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("David", 20F, FontStyle.Bold, GraphicsUnit.Point);
            label1.ForeColor = Color.WhiteSmoke;
            label1.Location = new Point(79, 37);
            label1.Name = "label1";
            label1.Size = new Size(185, 39);
            label1.TabIndex = 15;
            label1.Text = "Time left:";
            label1.TextAlign = ContentAlignment.MiddleCenter;
            label1.Visible = false;
            // 
            // timeShowText
            // 
            timeShowText.AutoSize = true;
            timeShowText.Font = new Font("David", 20F, FontStyle.Bold, GraphicsUnit.Point);
            timeShowText.ForeColor = Color.WhiteSmoke;
            timeShowText.Location = new Point(258, 37);
            timeShowText.Name = "timeShowText";
            timeShowText.Size = new Size(166, 39);
            timeShowText.TabIndex = 16;
            timeShowText.Text = "TimeExt";
            timeShowText.TextAlign = ContentAlignment.MiddleCenter;
            timeShowText.Visible = false;
            timeShowText.Click += label2_Click;
            // 
            // questionHolder
            // 
            questionHolder.BackColor = Color.DimGray;
            questionHolder.BorderStyle = BorderStyle.None;
            questionHolder.Font = new Font("David", 18F, FontStyle.Bold, GraphicsUnit.Point);
            questionHolder.ForeColor = Color.WhiteSmoke;
            questionHolder.Location = new Point(114, 156);
            questionHolder.Multiline = true;
            questionHolder.Name = "questionHolder";
            questionHolder.ReadOnly = true;
            questionHolder.Size = new Size(668, 109);
            questionHolder.TabIndex = 17;
            questionHolder.Text = "Question";
            questionHolder.TextAlign = HorizontalAlignment.Center;
            questionHolder.Visible = false;
            // 
            // WaitTextHolder
            // 
            WaitTextHolder.AutoSize = true;
            WaitTextHolder.Font = new Font("David", 22F, FontStyle.Bold, GraphicsUnit.Point);
            WaitTextHolder.ForeColor = Color.WhiteSmoke;
            WaitTextHolder.Location = new Point(12, 222);
            WaitTextHolder.Name = "WaitTextHolder";
            WaitTextHolder.Size = new Size(858, 43);
            WaitTextHolder.TabIndex = 18;
            WaitTextHolder.Text = "Please wait until all players finish the game...";
            WaitTextHolder.TextAlign = ContentAlignment.MiddleCenter;
            WaitTextHolder.Visible = false;
            // 
            // waitToggleHolder
            // 
            waitToggleHolder.AutoSize = true;
            waitToggleHolder.Font = new Font("David", 35F, FontStyle.Bold, GraphicsUnit.Point);
            waitToggleHolder.ForeColor = Color.Black;
            waitToggleHolder.Location = new Point(331, 294);
            waitToggleHolder.Name = "waitToggleHolder";
            waitToggleHolder.Size = new Size(202, 68);
            waitToggleHolder.TabIndex = 19;
            waitToggleHolder.Text = "( ͡° ͜ʖ ͡°)";
            waitToggleHolder.Visible = false;
            // 
            // GameForm
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.DimGray;
            ClientSize = new Size(880, 600);
            Controls.Add(waitToggleHolder);
            Controls.Add(WaitTextHolder);
            Controls.Add(questionHolder);
            Controls.Add(timeShowText);
            Controls.Add(label1);
            Controls.Add(timerBar);
            Controls.Add(aHolder2);
            Controls.Add(aHolder4);
            Controls.Add(aHolder1);
            Controls.Add(aHolder3);
            Controls.Add(GameCountDownTimer);
            Controls.Add(GameCountDown);
            Controls.Add(GameCountDownTextSaver);
            FormBorderStyle = FormBorderStyle.None;
            Name = "GameForm";
            Text = "GameForm";
            Load += GameForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label GameCountDownTextSaver;
        private Label GameCountDown;
        private Label GameCountDownTimer;
        private Label QuestionHolder;
        private designs.RoundedButton aHolder2;
        private designs.RoundedButton aHolder4;
        private designs.RoundedButton aHolder1;
        private designs.RoundedButton aHolder3;
        private ProgressBar timerBar;
        private Label label1;
        private Label timeShowText;
        private TextBox questionHolder;
        private Label WaitTextHolder;
        private Label waitToggleHolder;
    }
}