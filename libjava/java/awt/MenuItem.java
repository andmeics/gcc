/* MenuItem.java -- An item in a menu
   Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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


package java.awt;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.peer.MenuItemPeer;
import java.io.Serializable;
import java.lang.reflect.Array;
import java.util.EventListener;

import javax.accessibility.Accessible;
import javax.accessibility.AccessibleAction;
import javax.accessibility.AccessibleRole;
import javax.accessibility.AccessibleValue;

/**
  * This class represents an item in a menu.
  *
  * @author Aaron M. Renn (arenn@urbanophile.com)
  */
public class MenuItem extends MenuComponent
  implements Serializable, Accessible
{

/*
 * Static Variables
 */

// Serialization Constant
private static final long serialVersionUID = -21757335363267194L;

/*************************************************************************/

/*
 * Instance Variables
 */

/**
  * @serial The name of the action command generated by this item.
  */
private String actionCommand;

/**
  * @serial Indicates whether or not this menu item is enabled.
  */
private boolean enabled = true;

/**
  * @serial The mask of events that are enabled for this menu item.
  */
long eventMask;

/**
  * @serial This menu item's label
  */
private String label;

/**
  * @serial The shortcut for this menu item, if any
  */
private MenuShortcut shortcut;

// The list of action listeners for this menu item.
private transient ActionListener action_listeners;

  protected class AccessibleAWTMenuItem
    extends MenuComponent.AccessibleAWTMenuComponent
    implements AccessibleAction, AccessibleValue
  {
    /** Constructor */
    public AccessibleAWTMenuItem()
    {
      super();
    }
  
  
  
    public String getAccessibleName()
    {
      return label;
    }
  
    public AccessibleAction getAccessibleAction()
    {
      return this;
    }
  
    public AccessibleRole getAccessibleRole()
    {
      return AccessibleRole.MENU_ITEM;
    }
  
    /* (non-Javadoc)
     * @see javax.accessibility.AccessibleAction#getAccessibleActionCount()
     */
    public int getAccessibleActionCount()
    {
      return 1;
    }

    /* (non-Javadoc)
     * @see javax.accessibility.AccessibleAction#getAccessibleActionDescription(int)
     */
    public String getAccessibleActionDescription(int i)
    {
      if (i == 0)
	return label;
      else
	return null;
    }

    /* (non-Javadoc)
     * @see javax.accessibility.AccessibleAction#doAccessibleAction(int)
     */
    public boolean doAccessibleAction(int i)
    {
      if (i != 0)
	return false;
      processActionEvent(new ActionEvent(this, ActionEvent.ACTION_PERFORMED, actionCommand));
      return true;
    }

    public AccessibleValue getAccessibleValue()
    {
      return this;
    }
  
    /* (non-Javadoc)
     * @see javax.accessibility.AccessibleValue#getCurrentAccessibleValue()
     */
    public Number getCurrentAccessibleValue()
    {
      return (enabled) ? new Integer(1) : new Integer(0);
    }

    /* (non-Javadoc)
     * @see javax.accessibility.AccessibleValue#setCurrentAccessibleValue(java.lang.Number)
     */
    public boolean setCurrentAccessibleValue(Number number)
    {
      if (number.intValue() == 0)
	{
	  setEnabled(false);
	  return false;
	}
    
      setEnabled(true);
      return true;
    }

    /* (non-Javadoc)
     * @see javax.accessibility.AccessibleValue#getMinimumAccessibleValue()
     */
    public Number getMinimumAccessibleValue()
    {
      return new Integer(0);
    }

    /* (non-Javadoc)
     * @see javax.accessibility.AccessibleValue#getMaximumAccessibleValue()
     */
    public Number getMaximumAccessibleValue()
    {
      return new Integer(0);
    }
  
  }


/*************************************************************************/

/*
 * Constructors
 */

/**
  * Initializes a new instance of <code>MenuItem</code> with no label
  * and no shortcut.
  */
public
MenuItem()
{
}

/*************************************************************************/

/**
  * Initializes a new instance of <code>MenuItem</code> with the specified
  * label and no shortcut.
  *
  * @param label The label for this menu item.
  */
public 
MenuItem(String label)
{
  this.label = label;
}

/*************************************************************************/

/**
  * Initializes a new instance of <code>MenuItem</code> with the specified
  * label and shortcut.
  *
  * @param label The label for this menu item.
  * @param shortcut The shortcut for this menu item.
  */
public
MenuItem(String label, MenuShortcut shortcut)
{
  this.label = label;
  this.shortcut = shortcut;
}

/*************************************************************************/

/*
 * Instance Methods
 */

/**
  * Returns the label for this menu item, which may be <code>null</code>.
  *
  * @return The label for this menu item.
  */
public String
getLabel()
{
  return(label);
}

/*************************************************************************/

/**
  * This method sets the label for this menu to the specified value.
  *
  * @param label The new label for this menu item.
  */
public synchronized void
setLabel(String label)
{
  this.label = label;
  if (peer != null)
    {
      MenuItemPeer mp = (MenuItemPeer) peer;
      mp.setLabel (label);
    }
}

/*************************************************************************/

/**
  * Tests whether or not this menu item is enabled.
  *
  * @return <code>true</code> if this menu item is enabled, <code>false</code>
  * otherwise.
  */
public boolean
isEnabled()
{
  return(enabled);
}

/*************************************************************************/

/**
  * Sets the enabled status of this menu item.
  * 
  * @param enabled <code>true</code> to enable this menu item,
  * <code>false</code> otherwise.
  */
public synchronized void
setEnabled(boolean enabled)
{
  enable (enabled);
}

/*************************************************************************/

/**
  * Sets the enabled status of this menu item.
  * 
  * @param enabled <code>true</code> to enable this menu item,
  * <code>false</code> otherwise.
  *
  * @deprecated This method is deprecated in favor of <code>setEnabled()</code>.
  */
public void
enable(boolean enabled)
{
  if (enabled)
    enable ();
  else
    disable ();
}

/*************************************************************************/

/**
  * Enables this menu item.
  *
  * @deprecated This method is deprecated in favor of <code>setEnabled()</code>.
  */
public void
enable()
{
  if (enabled)
    return;

  this.enabled = true;
  if (peer != null)
    ((MenuItemPeer) peer).setEnabled (true);
}

/*************************************************************************/

/**
  * Disables this menu item.
  *
  * @deprecated This method is deprecated in favor of <code>setEnabled()</code>.
  */
public void
disable()
{
  if (!enabled)
    return;

  this.enabled = false;
  if (peer != null)
    ((MenuItemPeer) peer).setEnabled (false);
}

/*************************************************************************/

/**
  * Returns the shortcut for this menu item, which may be <code>null</code>.
  *
  * @return The shortcut for this menu item.
  */
public MenuShortcut
getShortcut()
{
  return(shortcut);
}

/*************************************************************************/

/**
  * Sets the shortcut for this menu item to the specified value.  This
  * must be done before the native peer is created.
  *
  * @param shortcut The new shortcut for this menu item.
  */
public void
setShortcut(MenuShortcut shortcut)
{
  this.shortcut = shortcut;
}

/*************************************************************************/

/**
  * Deletes the shortcut for this menu item if one exists.  This must be
  * done before the native peer is created.
  */
public void
deleteShortcut()
{
  shortcut = null;
}

/*************************************************************************/

/**
  * Returns the name of the action command in the action events
  * generated by this menu item.
  *
  * @return The action command name
  */
public String
getActionCommand()
{
  if (actionCommand == null)
    return label;
  else
    return actionCommand;
}

/*************************************************************************/

/**
  * Sets the name of the action command in the action events generated by
  * this menu item.
  *
  * @param actionCommand The new action command name.
  */
public void
setActionCommand(String actionCommand)
{
  this.actionCommand = actionCommand;
}

/*************************************************************************/

/**
  * Enables the specified events.  This is done automatically when a 
  * listener is added and does not normally need to be done by
  * application code.
  *
  * @param events The events to enable, which should be the bit masks
  * from <code>AWTEvent</code>.
  */
protected final void
enableEvents(long events)
{
  eventMask |= events;
  // TODO: see comment in Component.enableEvents().    
}

/*************************************************************************/

/**
  * Disables the specified events.
  *
  * @param events The events to enable, which should be the bit masks
  * from <code>AWTEvent</code>.
  */
protected final void
disableEvents(long events)
{
  eventMask &= ~events;
}

/*************************************************************************/

/**
  * Creates the native peer for this object.
  */
public void
addNotify()
{
  if (peer == null)
    peer = getToolkit ().createMenuItem (this);
}

/*************************************************************************/

/**
  * Adds the specified listener to the list of registered action listeners
  * for this component.
  *
  * @param listener The listener to add.
  */
public synchronized void
addActionListener(ActionListener listener)
{
  action_listeners = AWTEventMulticaster.add(action_listeners, listener);

  enableEvents(AWTEvent.ACTION_EVENT_MASK);
}

public synchronized void
removeActionListener(ActionListener l)
{
  action_listeners = AWTEventMulticaster.remove(action_listeners, l);
}

  public synchronized ActionListener[] getActionListeners()
  {
    return (ActionListener[])
      AWTEventMulticaster.getListeners(action_listeners,
                                       ActionListener.class);
  }

/** Returns all registered EventListers of the given listenerType. 
 * listenerType must be a subclass of EventListener, or a 
 * ClassClassException is thrown.
 * @since 1.3 
 */
  public EventListener[] getListeners(Class listenerType)
  {
    if (listenerType == ActionListener.class)
      return getActionListeners();
    return (EventListener[]) Array.newInstance(listenerType, 0);
  }

/*************************************************************************/

void
dispatchEventImpl(AWTEvent e)
{
  if (e.id <= ActionEvent.ACTION_LAST 
      && e.id >= ActionEvent.ACTION_FIRST
      && (action_listeners != null
	  || (eventMask & AWTEvent.ACTION_EVENT_MASK) != 0))
    processEvent(e);

  // Send the event to the parent menu if it has not yet been
  // consumed.
  if (!e.isConsumed ())
    ((Menu) getParent ()).processEvent (e);
}

/**
  * Processes the specified event by calling <code>processActionEvent()</code>
  * if it is an instance of <code>ActionEvent</code>.
  *
  * @param event The event to process.
  */
protected void
processEvent(AWTEvent event)
{
  if (event instanceof ActionEvent)
    processActionEvent((ActionEvent)event);
}

/*************************************************************************/

/**
  * Processes the specified event by dispatching it to any registered listeners.
  *
  * @param event The event to process.
  */
protected void
processActionEvent(ActionEvent event)
{
  if (action_listeners != null)
    action_listeners.actionPerformed(event);
}

/*************************************************************************/

/**
  * Returns a debugging string for this object.
  *
  * @return A debugging string for this object.
  */
public String
paramString()
{
  return ("label=" + label + ",enabled=" + enabled +
	  ",actionCommand=" + actionCommand + "," + super.paramString());
}

// Accessibility API not yet implemented.
// public AccessibleContext getAccessibleContext()

} // class MenuItem 
