/* LocaleInformation_se_NO.java
   Copyright (C) 2002 Free Software Foundation, Inc.

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


// This file was automatically generated by localedef.

package gnu.java.locale;

import java.util.ListResourceBundle;

public class LocaleInformation_se_NO extends ListResourceBundle
{
  static final String decimalSeparator = ",";
  static final String groupingSeparator = ".";
  static final String numberFormat = "#,###,##0.###";
  static final String percentFormat = "#,###,##0%";
  static final String[] weekdays = { null, "sotnabeaivi", "vuoss\u00E1rga", "ma\u014B\u014Bebarga", "gaskavahkku", "duorasdat", "bearjadat", "l\u00E1vvardat" };

  static final String[] shortWeekdays = { null, "sotn", "vuos", "ma\u014B", "gask", "duor", "bear", "l\u00E1v" };

  static final String[] shortMonths = { "o\u0111\u0111j", "guov", "njuk", "cuo\u014B", "mies", "geas", "suoi", "borg", "\u010Dak\u010D", "golg", "sk\u00E1b", "juov", null };

  static final String[] months = { "o\u0111\u0111ajagem\u00E1nu", "guovvam\u00E1nu", "njuk\u010Dam\u00E1nu", "cuo\u014Bom\u00E1nu", "miessem\u00E1nu", "geassem\u00E1nu", "suoidnem\u00E1nu", "borgem\u00E1nu", "\u010Dak\u010Dam\u00E1nu", "golggotm\u00E1nu", "sk\u00E1bmam\u00E1nu", "juovlam\u00E1nu", null };

  static final String[] ampms = { "", "" };

  static final String shortDateFormat = "yyyy-MM-dd";
  static final String defaultTimeFormat = "";
  static final String currencySymbol = " ru";
  static final String intlCurrencySymbol = "NOK";
  static final String currencyFormat = "$#,###,##0.00;$-#,###,##0.00";

  private static final Object[][] contents =
  {
    { "weekdays", weekdays },
    { "shortWeekdays", shortWeekdays },
    { "shortMonths", shortMonths },
    { "months", months },
    { "ampms", ampms },
    { "shortDateFormat", shortDateFormat },
    { "defaultTimeFormat", defaultTimeFormat },
    { "currencySymbol", currencySymbol },
    { "intlCurrencySymbol", intlCurrencySymbol },
    { "currencyFormat", currencyFormat },
    { "decimalSeparator", decimalSeparator },
    { "groupingSeparator", groupingSeparator },
    { "numberFormat", numberFormat },
    { "percentFormat", percentFormat },
  };

  public Object[][] getContents () { return contents; }
}
