using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ZHDM
{
    public partial class FormWelcome : Form
    {
        public FormWelcome()
        {
            InitializeComponent();
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if(panel2.Width < panel1.Width)
            {
                panel2.Width += 25;
            }
            else
            {
                this.DialogResult = DialogResult.OK;
            }
            
        }
    }
}
