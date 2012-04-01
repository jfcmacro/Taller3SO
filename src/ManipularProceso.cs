// ManipularProceso.cs
using System;
using System.Diagnostics;

public class ManipularProceso {
	public static void Main(string []args) {
		try {
			Process[] p = Process.GetProcessesByName("notepad");
			for (int i = 0; i < p.Length; i++) {
				Console.WriteLine("FileName: {0}", p[i].StartInfo.FileName);
				Console.WriteLine("Arguments: {0}", p[i].StartInfo.Arguments);
			}
		
			// Obtiene la información del estado el proceso notepad
			for (int i = 0; i < p.Length; i++) {
				p[i].WaitForExit();
				Console.WriteLine("ExitCode: {0}", p[i].ExitCode);
			}
		} catch (Exception e) {
			Console.WriteLine(e);
		}
	}
}