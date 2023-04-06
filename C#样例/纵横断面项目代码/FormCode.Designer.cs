namespace ZHDM
{
    partial class FormCode
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormCode));
            this.rtbCode = new System.Windows.Forms.RichTextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.rtbResult = new System.Windows.Forms.RichTextBox();
            this.SuspendLayout();
            // 
            // rtbCode
            // 
            this.rtbCode.Location = new System.Drawing.Point(12, 64);
            this.rtbCode.Name = "rtbCode";
            this.rtbCode.Size = new System.Drawing.Size(527, 275);
            this.rtbCode.TabIndex = 0;
            this.rtbCode.Text = resources.GetString("rtbCode.Text");
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(432, 26);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "运行";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // rtbResult
            // 
            this.rtbResult.Location = new System.Drawing.Point(30, 370);
            this.rtbResult.Name = "rtbResult";
            this.rtbResult.Size = new System.Drawing.Size(477, 60);
            this.rtbResult.TabIndex = 2;
            this.rtbResult.Text = "V0.1测试版本加载完成";
            // 
            // FormCode
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(551, 442);
            this.Controls.Add(this.rtbResult);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.rtbCode);
            this.Name = "FormCode";
            this.Text = "FormCode";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox rtbCode;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.RichTextBox rtbResult;
    }
}