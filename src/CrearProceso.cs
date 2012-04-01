// CrearProceso.cs
using System;
using System.Diagnostics;
using System.ComponentModel;

//
public class CrearProceso
{
        
	public static void Main(string []arg) {
		
		Process p = new Process();
		string pathDir = Environment.GetFolderPath(Environment.SpecialFolder.System);
		p.StartInfo.FileName = pathDir + "\\Notepad.exe";
		p.StartInfo.Arguments = "CrearProceso.cs";
		p.Start();
		p.WaitForExit();
		Console.WriteLine("Estado terminó: {0}", p.ExitCode);
	}
}