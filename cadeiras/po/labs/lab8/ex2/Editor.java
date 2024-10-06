import java.util.Map;
import java.util.TreeMap;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

/**
 * Form editor: allows the creation and manipulation of graphical forms such as
 * squares, circles, and lines. Forms can be created, moved, and deleted.
 * 
 * @author Programação com Objectos
 * @version 3.1
 */

public class Editor {

  /**
   * The forms held by the editor indexed by unique identifier.
   */
  private Map<Integer, Form> _formsMap = new TreeMap<Integer, Form>();
  
  /**
   * The forms held by the editor ordered by insertion time.
   */
  private List<Form> _forms = new ArrayList<Form>();
  
  /**
   * Give each form an unique identifier.
   */
  private int _nextId;
  
  /**
   * Add a form.
   * 
   * @param the form to add.
   * 
   * @return the added form's id.
   */
  public final int addForm(Form f) {
    int id = ++_nextId;
    _formsMap.put(id, f);
    _forms.add(f);
    return id;
  }
  
  /**
   * Get a form given its identifier.
   * 
   * @param id the form's identifier.
   * 
   * @return the form with the given identifier, or null if the form does not
   *         exist.
   */
  public final Form getForm(int id) throws NoSuchIdentifierException {
    Form form = _formsMap.get(id);
    if (form == null) throw new NoSuchIdentifierException(id);
    return form;
  }

  /**
   * Check whether a form exists (given an identifier).
   * 
   * @param id the identifier to check.
   * 
   * @return true, if the form exists; false, otherwise.
   */
  public final boolean formExists(int id) {
    return _formsMap.containsKey(id);
  }
  
  /**
   * Collection of all the forms held by the editor.
   *
   * @return the collection of forms of this editor ordered by insertion order.
   */
  public Collection<Form> getForms() {
    return Collections.unmodifiableCollection(_forms);
  }
  
  /**
   * Remove a given form (by id).
   * 
   * @param id the identifier of the form to be removed.
   * @return true if the editor contains a form with the specified identifier, false otherwise
   */
  public void remove(int id) throws NoSuchIdentifierException {
    Form form = _formsMap.remove(id);
    if (form == null)
      throw new NoSuchIdentifierException(id);
    }
}