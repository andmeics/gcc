/* JTextArea.java -- 
   Copyright (C) 2004  Free Software Foundation, Inc.

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

import java.awt.Dimension;
import java.awt.FontMetrics;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import javax.swing.text.Element;
import javax.swing.text.JTextComponent;
import javax.swing.text.PlainDocument;

public class JTextArea extends JTextComponent
{
  private static final long serialVersionUID = -6141680179310439825L;
  
  private int rows;
  private int columns;
  private boolean lineWrap;
  private int tabSize = 8;
  private boolean wrapStyleWord;

  /**
   * Creates a new <code>JTextArea</code> object.
   */
  public JTextArea()
  {
    this(null, null, 0, 0);
  }

  /**
   * Creates a new <code>JTextArea</code> object.
   *
   * @param text the initial text
   */
  public JTextArea(String text)
  {
    this(null, text, 0, 0);
  }

  /**
   * Creates a new <code>JTextArea</code> object.
   *
   * @param rows the number of rows
   * @param columns the number of cols
   *
   * @exception IllegalArgumentException if rows or columns are negative
   */
  public JTextArea(int rows, int columns)
  {
    this(null, null, rows, columns);
  }

  /**
   * Creates a new <code>JTextArea</code> object.
   *
   * @param text the initial text
   * @param rows the number of rows
   * @param columns the number of cols
   *
   * @exception IllegalArgumentException if rows or columns are negative
   */
  public JTextArea(String text, int rows, int columns)
  {
    this(null, text, rows, columns);
  }

  /**
   * Creates a new <code>JTextArea</code> object.
   *
   * @param the document model to use
   */
  public JTextArea(Document doc)
  {
    this(doc, null, 0, 0);
  }

  /**
   * Creates a new <code>JTextArea</code> object.
   *
   * @param the document model to use
   * @param text the initial text
   * @param rows the number of rows
   * @param columns the number of cols
   *
   * @exception IllegalArgumentException if rows or columns are negative
   */
  public JTextArea(Document doc, String text, int rows, int columns)
  {
    setDocument(doc == null ? createDefaultModel() : doc);
    setText(text);
    setRows(rows);
    setColumns(columns);
  }

  /**
   * Appends some text.
   *
   * @param toAppend the text to append
   */
  public void append(String toAppend)
  {
    setText(getText() + toAppend);
  }

  /**
   * Creates the default document model.
   *
   * @return a new default model
   */
  protected Document createDefaultModel()
  {
    return new PlainDocument();
  }


  public boolean getScrollableTracksViewportWidth()
  {
    return lineWrap ? true : super.getScrollableTracksViewportWidth();
  }

  /**
   * Returns the UI class ID string.
   *
   * @return the string "TextAreaUI"
   */
  public String getUIClassID()
  {
    return "TextAreaUI";
  }

  /**
   * Returns the current number of columns.
   *
   * @return number of columns
   */
  public int getColumns()
  {
    return columns;
  }
  
  /**
   * Sets the number of rows.
   *
   * @param columns number of columns
   *
   * @exception IllegalArgumentException if columns is negative
   */
  public void setColumns(int columns)
  {
    if (columns < 0)
      throw new IllegalArgumentException();

    this.columns = columns;
  }

  /**
   * Returns the current number of rows.
   *
   * @return number of rows
   */
  public int getRows()
  {
    return rows;
  }

  /**
   * Sets the number of rows.
   *
   * @param columns number of columns
   *
   * @exception IllegalArgumentException if rows is negative
   */
  public void setRows(int rows)
  {
    if (rows < 0)
      throw new IllegalArgumentException();

    this.rows = rows;
  }

  /**
   * Checks whether line wrapping is enabled.
   *
   * @return <code>true</code> if line wrapping is enabled,
   * <code>false</code> otherwise
   */
  public boolean getLineWrap()
  {
    return lineWrap;
  }

  /**
   * Enables/disables line wrapping.
   *
   * @param wrapping <code>true</code> to enable line wrapping,
   * <code>false</code> otherwise
   */
  public void setLineWrap(boolean flag)
  {
    if (lineWrap == flag)
      return;

    boolean oldValue = lineWrap;
    lineWrap = flag;
    firePropertyChange("lineWrap", oldValue, lineWrap);
  }

  /**
   * Checks whether word style wrapping is enabled.
   *
   * @return <code>true</code> if word style wrapping is enabled,
   * <code>false</code> otherwise
   */
  public boolean getWrapStyleWord()
  {
    return wrapStyleWord;
  }

  /**
   * Enables/Disables word style wrapping.
   *
   * @param flag <code>true</code> to enable word style wrapping,
   * <code>false</code> otherwise
   */
  public void setWrapStyleWord(boolean flag)
  {
    if (wrapStyleWord == flag)
      return;

    boolean oldValue = wrapStyleWord;
    wrapStyleWord = flag;
    firePropertyChange("wrapStyleWord", oldValue, wrapStyleWord);
  }

  public int getTabSize()
  {
    return tabSize;
  }

  public void setTabSize(int newSize)
  {
    if (tabSize == newSize)
      return;
    
    int oldValue = tabSize;
    tabSize = newSize;
    firePropertyChange("tabSize", oldValue, tabSize);
  }

  protected int getColumnWidth()
  {
    FontMetrics metrics = getToolkit().getFontMetrics(getFont());
    return metrics.charWidth('m');
  }

  public int getLineCount()
  {
    return doc.getDefaultRootElement().getElementCount();
  }

  public int getLineStartOffset(int line)
     throws BadLocationException
  {
    int lineCount = getLineCount();
    
    if (line < 0 || line > lineCount)
      throw new BadLocationException("Non-existing line number", line);

    Element lineElem = doc.getDefaultRootElement().getElement(line);
    return lineElem.getStartOffset();
  }

  public int getLineEndOffset(int line)
     throws BadLocationException
  {
    int lineCount = getLineCount();
    
    if (line < 0 || line > lineCount)
      throw new BadLocationException("Non-existing line number", line);

    Element lineElem = doc.getDefaultRootElement().getElement(line);
    return lineElem.getEndOffset();
  }

  public int getLineOfOffset(int offset)
    throws BadLocationException
  {
    if (offset < doc.getStartPosition().getOffset()
	|| offset >= doc.getEndPosition().getOffset())
      throw new BadLocationException("offset outside of document", offset);

    return doc.getDefaultRootElement().getElementIndex(offset);
  }

  protected int getRowHeight()
  {
    FontMetrics metrics = getToolkit().getFontMetrics(getFont());
    return metrics.getHeight();
  }

  public void insert(String text, int offset)
  {
    if (offset < doc.getStartPosition().getOffset()
	|| offset >= doc.getEndPosition().getOffset())
      throw new IllegalArgumentException();

    try
      {
	doc.insertString(offset, text, null);
      }
    catch (BadLocationException e)
      {
	// This cannot happen as we check offset above.
      }
  }

  public void replaceRange(String text, int start, int end)
  {
    if (start > end
	|| start < doc.getStartPosition().getOffset()
	|| end >= doc.getEndPosition().getOffset())
      throw new IllegalArgumentException();

    try
      {
	doc.remove(start, end);
	doc.insertString(start, text, null);
      }
    catch (BadLocationException e)
      {
	// This cannot happen as we check offset above.
      }
  }
}
