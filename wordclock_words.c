/* 
(c) 2016 - Dominique Görsch - <mail@dgoersch.info>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
Dieses Programm ist Freie Software: Sie können es unter den Bedingungen
der GNU General Public License, wie von der Free Software Foundation,
Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
veröffentlichten Version, weiterverbreiten und/oder modifizieren.
Dieses Programm wird in der Hoffnung, dass es nützlich sein wird, aber
OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
Siehe die GNU General Public License für weitere Details.
Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>. 
*/

void min_ONE() {
  toStrip(MIN1);
}

void min_TWO() {
  toStrip(MIN2);
}

void min_THREE() {
  toStrip(MIN3);
}

void min_FOUR() {
  toStrip(MIN4);
}

void word_KEIN() {
  toStrip(X1Y6);
  toStrip(X2Y6);
  toStrip(X3Y6);
  toStrip(X4Y6);
}

void word_FUNK() {
  toStrip(X4Y4);
  toStrip(X5Y4);
  toStrip(X6Y4);
  toStrip(X7Y4);
}

void word_ES() {
  toStripe(X1Y1);
  toStripe(X2Y1);
}

void word_IST() {
  toStripe(X4Y1);
  toStripe(X5Y1);
  toStripe(X6Y1);
}

void word_UHR() {
  toStrip(X9Y10);
  toStrip(X10Y10);
  toStrip(X11Y10);
}

void word_VOR() {
  toStrip(X1Y4);
  toStrip(X2Y4);
  toStrip(X3Y4);
}

void word_NACH() {
  toStrip(X8Y4);
  toStrip(X9Y4);
  toStrip(X10Y4);
  toStrip(X11Y4);
}

void word_VIERTEL() {
  toStrip(X5Y3);
  toStrip(X6Y3);
  toStrip(X7Y3);
  toStrip(X8Y3);
  toStrip(X9Y3);
  toStrip(X10Y3);
  toStrip(X11Y3);
}

void word_HALB() {
  toStrip(X1Y5);
  toStrip(X2Y5);
  toStrip(X3Y5);
  toStrip(X4Y5);
}

void word_EINS(bool s) {
  toStrip(X2Y6);
  toStrip(X3Y6);
  toStrip(X4Y6);
  if (s) { toStrip(X5Y6); }
}

void word_ZWEI() {
  toStrip(X8Y6);
  toStrip(X9Y6);
  toStrip(X10Y6);
  toStrip(X11Y6);
}

void word_DREI() {
  toStrip(X1Y7);
  toStrip(X2Y7);
  toStrip(X3Y7);
  toStrip(X4Y7);
}

void word_VIER() {
  toStrip(X8Y7);
  toStrip(X9Y7);
  toStrip(X10Y7);
  toStrip(X11Y7);
}

void word_FUENF1() {
  toStripe(X8Y1);
  toStripe(X9Y1);
  toStripe(X10Y1);
  toStripe(X11Y1);
}

void word_FUENF2() {
  toStripe(X8Y5);
  toStripe(X9Y5);
  toStripe(X10Y5);
  toStripe(X11Y5);
}

void word_SECHS() {
  toStrip(X1Y8);
  toStrip(X2Y8);
  toStrip(X3Y8);
  toStrip(X4Y8);
  toStrip(X5Y8);
}

void word_SIEBEN() {
  toStrip(X1Y9);
  toStrip(X2Y9);
  toStrip(X3Y9);
  toStrip(X4Y9);
  toStrip(X5Y9);
  toStrip(X6Y9);
}

void word_ACHT() {
  toStrip(X8Y8);
  toStrip(X9Y8);
  toStrip(X10Y8);
  toStrip(X11Y8);
}

void word_NEUN() {
  toStrip(X4Y10);
  toStrip(X5Y10);
  toStrip(X6Y10);
  toStrip(X7Y10);
}

void word_ZEHN1() {
  toStrip(X1Y2);
  toStrip(X2Y2);
  toStrip(X3Y2);
  toStrip(X4Y2);
}

void word_ZEHN2() {
  toStrip(X1Y10);
  toStrip(X2Y10);
  toStrip(X3Y10);
  toStrip(X4Y10);
}

void word_ELF() {
  toStrip(X6Y5);
  toStrip(X7Y5);
  toStrip(X8Y5);
}

void word_ZWOELF() {
  toStrip(X7Y9);
  toStrip(X8Y9);
  toStrip(X9Y9);
  toStrip(X10Y9);
  toStrip(X11Y9);
}

void word_ZWANZIG() {
  toStrip(X5Y2);
  toStrip(X6Y2);
  toStrip(X7Y2);
  toStrip(X8Y2);
  toStrip(X9Y2);
  toStrip(X10Y2);
  toStrip(X11Y2);
}
