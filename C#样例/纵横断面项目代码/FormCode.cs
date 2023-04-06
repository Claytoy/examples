using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Microsoft.CSharp;
using System.CodeDom.Compiler;
using System.Reflection;


namespace ZHDM
{
    public partial class FormCode : Form
    {
        public FormCode()
        {
            InitializeComponent();
        }



    private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                //【1】新建C#代码生成器和代码编译器的实例
                CodeDomProvider Provider = CodeDomProvider.CreateProvider("CSharp");
                //【2】配置用于调用编译器的参数
                CompilerParameters Parameters = new CompilerParameters();
                Parameters.ReferencedAssemblies.Add("System.dll");
                Parameters.ReferencedAssemblies.Add("System.Windows.Forms.dll");
                Parameters.ReferencedAssemblies.Add("System.Linq.dll");
                Parameters.GenerateExecutable = false;
                Parameters.GenerateInMemory = true;
                rtbResult.Text += "dll链接完成.....\r\n";
                //【3】启动编译
                rtbResult.Text += "启动编译.....\r\n";

                CompilerResults Result = Provider.CompileAssemblyFromSource(Parameters, rtbCode.Text);
                rtbResult.Text += "实例生成完成.....\r\n";
                rtbResult.Text += "进入线程.....\r\n";
                Assembly objAssembly = Result.CompiledAssembly;
                object objHelloWorld = objAssembly.CreateInstance("CodeEditor.CodeEdit.Code");
                MethodInfo objMI = objHelloWorld.GetType().GetMethod("Test");

                object ReValue = objMI.Invoke(objHelloWorld, null);
                rtbResult.Text += "线程退出  return 0 \r\n";
                
            }
            catch(Exception ex) { rtbResult.Text += ex.Message; }
        }
    }
}