/* Project Euler
 * - JustCoderdev solution to 013 - 2024.03.03
 *
 *
 * Large Sum
 *  Work out the first ten digits of the sum
 *  of the following one-hundred 50-digit number.
 *
 */

#include <stdio.h>

#include "lib/jctypes.h"

int main(void)
{
	const double DIGITS[100] = {
		371072875339021e35, 463769376774900e35, 743249861995247e35,
		919422133635741e35, 230675882075393e35, 892616706966236e35,
		281128798128499e35, 442742289174325e35, 474514457360013e35,
		703864861058430e35, 621764571418565e35, 649063524627419e35,
		925758677183372e35, 582035653253593e35, 801811993848262e35,
		353986643728271e35, 865155060062958e35, 716938887077154e35,
		543700705768266e35, 532826541087568e35, 361232725250002e35,
		458765761724109e35, 174237069058518e35, 811426604180868e35,
		519343254517283e35, 624672216484350e35, 157324443869081e35,
		550376875256787e35, 183363848253301e35, 803862875928784e35,
		781828337579931e35, 167263201004368e35, 484030981290777e35,
		870869875513927e35, 599594068957565e35, 697939506796526e35,
		410526847082990e35, 653786073615010e35, 358290353174347e35,
		949537597651053e35, 889028025717332e35, 252676802760780e35,
		362702185404977e35, 240744869082311e35, 914302881971032e35,
		344130655780161e35, 230530811728164e35, 114876969321549e35,
		637832994906362e35, 677201869716985e35, 955482553002635e35,
		760853271322857e35, 377742425354112e35, 237019132757256e35,
		297988602722583e35, 184957014548792e35, 382982037830314e35,
		348295438291999e35, 409579530664052e35, 297461521855023e35,
		416981162220729e35, 624679571944012e35, 231897067725479e35,
		861880882258753e35, 113067397083047e35, 829591747671403e35,
		976233310448183e35, 428462801835170e35, 551216035469812e35,
		322381957343293e35, 755061649651847e35, 621778427521926e35,
		329241857071473e35, 995186714302352e35, 732674608005915e35,
		768418225246744e35, 971426179103425e35, 877836461827993e35,
		108488025216746e35, 713296124747824e35, 621840735723997e35,
		666278919814880e35, 606618262936828e35, 857869440895529e35,
		660243964099053e35, 649139826800329e35, 167309393198727e35,
		948093772450487e35, 786391670211874e35, 153687137119366e35,
		407899231155355e35, 448899115014406e35, 415031288803395e35,
		812348806732101e35, 826165707739483e35, 229188020587773e35,
		771585425020165e35, 721078384350691e35, 208496039801340e35,
		535035342264725e35};

	n64 i;
	double sum = 0;

	for(i = 0; i < 100; ++i)
	{
		sum += DIGITS[i];
	}

	printf("The sum of the digits is %lf\n", sum);

	return 0;
}