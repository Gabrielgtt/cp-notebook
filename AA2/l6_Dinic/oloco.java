import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class GrupoTest {

	private Grupo grupo1a;
	private Grupo grupo1b;
	private Grupo grupo2;
	
	@Before
	public void initialize() {
		this.grupo1a = new Grupo("AA");
		this.grupo1b = new Grupo("BB");
		this.grupo2 = new Grupo("CC");
	}
	
	@Test
	public void equalsGrupoIguais() {
		assertEquals("grupos iguais considerados diferentes", grupo1a.equals(grupo1b), true);
	}

	@Test
	public void equalsGrupoDif() {
		assertEquals("grupos iguais considerados diferentes", grupo1a.equals(grupo2), false);
	}

}
