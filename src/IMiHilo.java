// IMiHilo.java

public class IMiHilo implements Runnable {

    public IMiHilo(int tiempoEspera) {
	
	this.tiempoEspera = tiempoEspera;
    }

    private int tiempoEspera;

    // Método principal
    public void run() {

	for (int i = 0; i < 1000; i++) {
	    
	    System.out.println("Hilo: " + 
			       Thread.currentThread().getName() +
			       " iteracion: " + i);
	    try {
		Thread.sleep(tiempoEspera);
	    } catch (InterruptedException ie) { } // No hace nada
	}
	
    }

    // Punto de entrada del programa
    public static void main(String args[]) {

	IMiHilo imh1 = new IMiHilo(1000);
	IMiHilo imh2 = new IMiHilo(2000);
	IMiHilo imh3 = new IMiHilo(1500);

	Thread t1 = new Thread(imh1, "Mi Hilo 1");
	Thread t2 = new Thread(imh2, "Mi Hilo 2");
	Thread t3 = new Thread(imh3, "Mi Hilo 3");

	t1.start(); // Inicia el hilo 1
	t2.start(); // Inicia el hilo 2
	t3.start(); // Inicia el hilo 3

	System.out.println("Termina el hilo de control");
    }
}
