// This file was automatically generated by localedef.

package gnu.java.locale;

import java.util.ListResourceBundle;

public class LocaleInformation_de_CH extends ListResourceBundle
{
  static final String decimalSeparator = ".";
  static final String groupingSeparator = " ";
  static final String numberFormat = "#,###,##0.###";
  static final String percentFormat = "#,###,##0%";
  static final String[] weekdays = { null, "Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag" };

  static final String[] shortWeekdays = { null, "Son", "Mon", "Die", "Mit", "Don", "Fre", "Sam" };

  static final String[] shortMonths = { "Jan", "Feb", "M\u00E4r", "Apr", "Mai", "Jun", "Jul", "Aug", "Sep", "Okt", "Nov", "Dez", null };

  static final String[] months = { "Januar", "Februar", "M\u00E4rz", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember", null };

  static final String[] ampms = { "", "" };

  static final String shortDateFormat = "yyyy-MM-dd";
  static final String defaultTimeFormat = "";
  static final String currencySymbol = "Fr.";
  static final String intlCurrencySymbol = "CHF";
  static final String currencyFormat = "$ #,###,##0.00;$ -#,###,##0.00";

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
