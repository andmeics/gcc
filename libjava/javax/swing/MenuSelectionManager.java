/* MenuSelectionManager.java --
   Copyright (C) 2002, 2004 Free Software Foundation, Inc.

This file is part of GNU Classpath.

GNU Classpath is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Classpath is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Classpath; see the file COPYING.  If not, write to the
Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
02111-1307 USA.

Linking this library statically or dynamically with other modules is
making a combined work based on this library.  Thus, the terms and
conditions of the GNU General Public License cover the whole
combination.

As a special exception, the copyright holders of this library give you
permission to link this library with independent modules to produce an
executable, regardless of the license terms of these independent
modules, and to copy and distribute the resulting executable under
terms of your choice, provided that you also meet, for each linked
independent module, the terms and conditions of the license of that
module.  An independent module is a module which is not derived from
or based on this library.  If you modify this library, you may extend
this exception to your version of the library, but you are not
obligated to do so.  If you do not wish to do so, delete this
exception statement from your version. */

package javax.swing;

import java.awt.Component;
import java.awt.Point;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.util.Vector;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.EventListenerList;


/**
 * This class manages current menu selectection. It provides
 * methods to clear and set current selected menu path.
 * It also fires StateChange event to its registered
 * listeners whenever selected path of the current menu hierarchy
 * changes.
 *
 */
public class MenuSelectionManager
{
  /** ChangeEvent fired when selected path changes*/
  protected ChangeEvent changeEvent = new ChangeEvent(this);

  /** List of listeners for this MenuSelectionManager */
  protected EventListenerList listenerList = new EventListenerList();

  /** Default manager for the current menu hierarchy*/
  private static final MenuSelectionManager manager = new MenuSelectionManager();

  /** Path to the currently selected menu */
  private Vector selectedPath = new Vector();

  /**
   * Fires StateChange event to registered listeners
   */
  protected void fireStateChanged()
  {
    ChangeListener[] listeners = getChangeListeners();

    for (int i = 0; i < listeners.length; i++)
      listeners[i].stateChanged(changeEvent);
  }

  /**
   * Adds ChangeListener to this MenuSelectionManager
   *
   * @param listener ChangeListener to add
   */
  public void addChangeListener(ChangeListener listener)
  {
    listenerList.add(ChangeListener.class, listener);
  }

  /**
   * Removes ChangeListener from the list of registered listeners
   * for this MenuSelectionManager.
   *
   * @param listener ChangeListner to remove
   */
  public void removeChangeListener(ChangeListener listener)
  {
    listenerList.remove(ChangeListener.class, listener);
  }

  /**
   * Returns list of registered listeners with MenuSelectionManager
   *
   * @since 1.4
   */
  public ChangeListener[] getChangeListeners()
  {
    return (ChangeListener[]) listenerList.getListeners(ChangeListener.class);
  }

  /**
   * Unselects all the menu elements on the selection path
   */
  public void clearSelectedPath()
  {
    // Send events from the bottom most item in the menu - hierarchy to the
    // top most
    for (int i = selectedPath.size() - 1; i >= 0; i--)
      ((MenuElement) selectedPath.get(i)).menuSelectionChanged(false);

    // notify all listeners that the selected path was changed    
    fireStateChanged();

    // clear selected path
    selectedPath.clear();
  }

  /**
   * DOCUMENT ME!
   *
   * @param source DOCUMENT ME!
   * @param sourcePoint DOCUMENT ME!
   *
   * @return DOCUMENT ME!
   */
  public Component componentForPoint(Component source, Point sourcePoint)
  {
    throw new UnsupportedOperationException("not implemented");
  }

  /**
   * Returns shared instance of MenuSelection Manager
   *
   * @return default Manager
   */
  public static MenuSelectionManager defaultManager()
  {
    return manager;
  }

  /**
   * Returns path representing current menu selection
   *
   * @return Current selection path
   */
  public MenuElement[] getSelectedPath()
  {
    MenuElement[] path = new MenuElement[selectedPath.size()];

    for (int i = 0; i < path.length; i++)
      path[i] = (MenuElement) selectedPath.get(i);

    return path;
  }

  /**
   * Returns true if specified component is part of current menu
   * heirarchy and false otherwise
   *
   * @param c Component for which to check
   * @return True if specified component is part of current menu
   */
  boolean isComponentPartOfCurrentMenu(Component c)
  {
    MenuElement[] subElements;
    for (int i = 0; i < selectedPath.size(); i++)
      {
	subElements = ((MenuElement) selectedPath.get(i)).getSubElements();
	for (int j = 0; j < subElements.length; j++)
	  {
	    if ((subElements[j].getComponent()).equals(c))
	      return true;
	  }
      }

    return false;
  }

  /**
   * DOCUMENT ME!
   *
   * @param e DOCUMENT ME!
   */
  public void processKeyEvent(KeyEvent e)
  {
    throw new UnsupportedOperationException("not implemented");
  }

  /**
   * Forwards given mouse event to all of the source subcomponents.
   *
   * @param event Mouse event
   */
  public void processMouseEvent(MouseEvent event)
  {
    Component c = ((Component) event.getSource());

    MenuElement[] path = getPath(c);
    ((MenuElement) c).processMouseEvent(event, path, manager);

    // forward events to subcomponents 
    MenuElement[] subComponents = ((MenuElement) c).getSubElements();

    for (int i = 0; i < subComponents.length; i++)
      {
	if (subComponents[i] instanceof JMenuItem)
	  subComponents[i].processMouseEvent(event, path, manager);
      }
  }

  /**
   * Sets menu selection to the specified path
   *
   * @param path new selection path
   */
  public void setSelectedPath(MenuElement[] path)
  {
    if (path == null)
      {
	clearSelectedPath();
	return;
      }

    fireStateChanged();

    int i;
    int minSize = path.length; // size of the smaller path. 

    if (path.length > selectedPath.size())
      {
	// if new selected path contains more elements then current
	// selection then first add all elements at 
	// the indexes > selectedPath.size 
	for (i = selectedPath.size(); i < path.length; i++)
	  {
	    selectedPath.add(path[i]);
	    path[i].menuSelectionChanged(true);
	  }

	minSize = selectedPath.size();
      }

    else if (path.length < selectedPath.size())
      {
	// if new selected path contains less elements then current 
	// selection then first remove all elements from the selection
	// at the indexes > path.length
	for (i = selectedPath.size() - 1; i >= path.length; i--)
	  {
	    ((MenuElement) selectedPath.get(i)).menuSelectionChanged(false);
	    selectedPath.remove(i);
	  }

	minSize = path.length;
      }

    // Now compare elements in new and current selection path at the 
    // same location and adjust selection until 
    // same menu elements will be encountered at the
    // same index in both current and new selection path.
    MenuElement oldSelectedPath;

    for (i = minSize - 1; i >= 0; i--)
      {
	oldSelectedPath = (MenuElement) selectedPath.get(i);

	if (path[i].equals(oldSelectedPath))
	  break;

	oldSelectedPath.menuSelectionChanged(false);
	path[i].menuSelectionChanged(true);
	selectedPath.setElementAt(path[i], i);
      }
  }

  /**
   * Returns path to the specified component
   *
   * @param c component for which to find path for
   *
   * @return path to the specified component
   */
  private MenuElement[] getPath(Component c)
  {
    ArrayList path = new ArrayList();
    while (c instanceof MenuElement)
      {
	path.add(0, (MenuElement) c);

	if (c instanceof JPopupMenu)
	  c = ((JPopupMenu) c).getInvoker();
	else
	  c = c.getParent();
      }

    MenuElement[] pathArray = new MenuElement[path.size()];
    path.toArray(pathArray);
    return pathArray;
  }
}
