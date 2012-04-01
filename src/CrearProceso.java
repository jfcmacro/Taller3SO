// CrearProceso.java

public class CrearProceso {

    public static void main(String args[]) {
	try {
	    Runtime r = Runtime.getRuntime();
	    Process p = r.exec("Notepad CrearProceso.java");
	    p.waitFor();
	    System.out.println("Estado de retorno: " + p.exitValue());
	} catch (Exception e) {
	    System.err.println("Error: " + e);
	    System.exit(1);
	}
    }
}
