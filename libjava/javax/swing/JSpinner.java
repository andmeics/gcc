/* JSpinner.java --
   Copyright (C) 2004 Free Software Foundation, Inc.

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

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.LayoutManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.text.DecimalFormat;
import java.text.ParseException;
import javax.swing.border.EtchedBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.EventListenerList;
import javax.swing.plaf.SpinnerUI;
import java.util.EventListener;

/**
 * A JSpinner is a component which typically contains a numeric value and a
 * way to manipulate the value.
 *
 * @author	Ka-Hing Cheung
 * @version	1.0
 */
public class JSpinner extends JComponent 
{
  public static class StubEditor extends JLabel implements ChangeListener
  {
    private JLabel label;
    private JButton up;
    private JButton down;
    private JSpinner spinner;
    
    public StubEditor(JSpinner spinner)
    {
      this.spinner = spinner;
      setBorder(new EtchedBorder());
      setHorizontalAlignment(SwingConstants.TRAILING);
      stateChanged(null); /* fill in the label */
    }

    public void stateChanged(ChangeEvent evt)
    {
      setText(String.valueOf(spinner.getValue()));
    }
  }

  public static class DefaultEditor extends JPanel
    implements ChangeListener, PropertyChangeListener, LayoutManager
  {
    public DefaultEditor(JSpinner spinner)
    {
      spinner.addChangeListener(this);
    } /* TODO */

    public void commitEdit()
    {
    } /* TODO */

    public void dismiss(JSpinner spinner)
    {
      spinner.removeChangeListener(this);
    }

    public JFormattedTextField getTextField()
    {
      return null;
    } /* TODO */

    public void layoutContainer(Container parent)
    {

    } /* TODO */

    public Dimension minimumLayoutSize(Container parent)
    {
      return null;
    } /* TODO */

    public Dimension preferredLayoutSize(Container parent)
    {
      return null;
    } /* TODO */

    public void propertyChange(PropertyChangeEvent evt)
    {

    } /* TODO */

    public void stateChanged(ChangeEvent evt)
    {

    } /* TODO */

    /* no-ops */
    public void removeLayoutComponent(Component child)
    {
    }

    public void addLayoutComponent(String name, Component child)
    {
    }
  }

  public static class NumberEditor extends DefaultEditor
  {
    public NumberEditor(JSpinner spinner)
    {
      super(spinner);
    }

    public DecimalFormat getFormat()
    {
      return null;
    }
  }

  private SpinnerModel model;
  private JComponent editor;
  private EventListenerList listenerList = new EventListenerList();
  
  private ChangeListener listener = new ChangeListener()
    {
      public void stateChanged(ChangeEvent evt)
      {
        fireStateChanged();
      }
    };

  /**
   * Creates a JSpinner with <code>SpinnerNumberModel</code>
   *
   * @see javax.swing.SpinnerNumberModel
   */
  public JSpinner()
  {
    this(new SpinnerNumberModel());
  }

  /**
   * Creates a JSpinner with the specific model and sets the default editor
   */
  public JSpinner(SpinnerModel model)
  {
    this.model = model;
    model.addChangeListener(listener);
    setEditor(createEditor(model));
    updateUI();
  }

  /**
   * If the editor is <code>JSpinner.DefaultEditor</code>, then forwards the
   * call to it, otherwise do nothing.
   */
  public void commitEdit() throws ParseException
  {
    if(editor instanceof DefaultEditor)
      ((DefaultEditor)editor).commitEdit();
  }

  /**
   * Gets the current editor
   *
   * @return the current editor
   * @see #setEditor
   */
  public JComponent getEditor()
  {
    return editor;
  }

  /**
   * Changes the current editor to the new editor. This methods should remove
   * the old listeners (if any) and adds the new listeners (if any).
   *
   * @param editor the new editor
   * @see #getEditor
   */
  public void setEditor(JComponent editor)
  {
    if(editor == null)
      throw new IllegalArgumentException("editor may not be null");

    if(this.editor instanceof DefaultEditor)
      ((DefaultEditor)editor).dismiss(this);
    else if(this.editor instanceof ChangeListener)
      removeChangeListener((ChangeListener)this.editor);

    if(editor instanceof ChangeListener)
      addChangeListener((ChangeListener)editor);

    this.editor = editor;
  }

  /**
   * Gets the underly model.
   *
   * @return the underly model
   */
  public SpinnerModel getModel()
  {
    return model;
  }

  /**
   * Gets the next value without changing the current value.
   *
   * @return the next value
   * @see javax.swing.SpinnerModel#getNextValue
   */
  public Object getNextValue()
  {
    return model.getNextValue();
  }

  /**
   * Gets the previous value without changing the current value.
   *
   * @return the previous value
   * @see javax.swing.SpinnerModel#getPreviousValue
   */
  public Object getPreviousValue()
  {
    return model.getPreviousValue();
  }

  /**
   * Gets the <code>SpinnerUI</code> that handles this spinner
   *
   * @return the <code>SpinnerUI</code>
   */
  public SpinnerUI getUI()
  {
    return (SpinnerUI)ui;
  }

  /**
   * Gets the current value of the spinner, according to the underly model, not
   * the UI.
   *
   * @return the current value
   * @see javax.swing.SpinnerModel#getValue
   */
  public Object getValue()
  {
    return model.getValue();
  }

  /**
   * This method returns a name to identify which look and feel class will be
   * the UI delegate for this spinner.
   *
   * @return The UIClass identifier. "SpinnerUI"
   */
  public String getUIClassID()
  {
    return "SpinnerUI";
  }

  /**
   * This method resets the spinner's UI delegate to the default UI for the
   * current look and feel.
   */
  public void updateUI()
  {
    setUI((SpinnerUI) UIManager.getUI(this));
  }

  /**
   * This method sets the spinner's UI delegate.
   *
   * @param ui The spinner's UI delegate.
   */
  public void setUI(SpinnerUI ui)
  {
    super.setUI(ui);
  }

  /**
   * Adds a <code>ChangeListener</code> 
   *
   * @param listener the listener to add
   */
  public void addChangeListener(ChangeListener listener)
  {
    listenerList.add(ChangeListener.class, listener);
  }

  /**
   * Remove a particular listener
   *
   * @param listener the listener to remove
   */
  public void removeChangeListener(ChangeListener listener)
  {
    listenerList.remove(ChangeListener.class, listener);
  }

  /**
   * Gets all the <code>ChangeListener</code>s
   *
   * @return all the <code>ChangeListener</code>s
   */
  public ChangeListener[] getChangeListeners()
  {
    return (ChangeListener[]) listenerList.getListeners(ChangeListener.class);;    
  }

  /**
   * Fires a <code>ChangeEvent</code> to all the <code>ChangeListener</code>s
   * added to this <code>JSpinner</code>
   */
  protected void fireStateChanged()
  {
    ChangeEvent evt = new ChangeEvent(this);
    ChangeListener[] listeners = getChangeListeners();

    for(int i = 0; i < listeners.length; ++i)
      listeners[i].stateChanged(evt);
  }

  /**
   * Creates an editor for this <code>JSpinner</code>. Really, it should be a
   * <code>JSpinner.DefaultEditor</code>, but since that should be implemented
   * by a JFormattedTextField, and one is not written, I am just using a dummy
   * one backed by a JLabel.
   *
   * @return the default editor
   */
  protected JComponent createEditor(SpinnerModel model)
  {
    return new StubEditor(this);
  } /* TODO */
}
