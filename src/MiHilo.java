// MiHilo.java

public class MiHilo extends Thread {

    private int tiempoEspera;

    public MiHilo(String nombreHilo, int tiempoEspera) {
	super(nombreHilo);
	this.tiempoEspera = tiempoEspera;
    }

    public void run() {
	
	for (int i = 0; i < 1000; i++) {
	    System.out.println("Hilo: " + getName() +
			       " ejecución " + i);

	    try {
		Thread.sleep(tiempoEspera);
	    } catch (InterruptedException ie) { } // No importa
	}
    }

    public static void main(String args[]) {

	MiHilo mh1 = new MiHilo("Hilo 1", 1000); // Espera un segundo
	// El tiempo es en milisegundos
	MiHilo mh2 = new MiHilo("Hilo 2", 2000);

	// Están creadas las clases de hilos pero no se han 
	// puesto ha ejecutar.

	mh1.start(); // Se inicia hilo 1
	mh2.start(); // Se inicia hilo 2
	// Hilo de control termina, pero los hilos continuan.

	System.out.println("Hilo de control termina");
    }
}
