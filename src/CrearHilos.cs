// CrearHilos.cs
using System;
using System.Threading;

public class CrearHilos {
	
	public static void Hilo() {
	
		for (int i = 0; i < 10; i++) {
		    Console.WriteLine("Hilo: {0}", i);
		    Thread.Sleep(1000); // Duerme un segundo
		}
        }

	public static void Main() {

		Thread t = new Thread(new ThreadStart(Hilo));
		t.Start();
		
		Console.WriteLine("El hilo de control ha terminado");
	}
}