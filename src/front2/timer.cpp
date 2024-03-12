/*
 * MONA
 * Copyright (C) 1997-2008 BRICS.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the  Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
 * USA.
 */
/*
Modified for MonaGUI
Copyright 2011 Michael Kruse
*/

#define _LANGUAGE_C_PLUS_PLUS

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include "timer.h"
#include <iostream>
#include <iomanip>
#include <boost/chrono.hpp>


#if 0
const unsigned long hour = 360000;
const unsigned long min  = 6000;
const unsigned long sec  = 100;

const unsigned long step = 2000; // sec. pr. step

static unsigned long prev, clocks, steps; // CPU time (user+system)

void
refresh(int) {
    unsigned long t = (unsigned long) clock();
    clocks += t - prev;
    prev = t;
    while (clocks >= step*CLOCKS_PER_SEC) {
        steps++;
        clocks -= step*CLOCKS_PER_SEC;
    }
    //signal(SIGALRM, &refresh);
    //alarm(step);
}
#endif

void
initTimer() {
    //clocks = steps = 0;
    //refresh(0);
}

void
Timer::start() {
    begin = boost::chrono::high_resolution_clock::now();

    // clock_gettime();
    //  time(&begin);

#if 0
    //alarm(0);
    refresh(0);
    tsteps = steps;
    tclocks = clocks;
#endif
}

void
Timer::stop() {
    end = boost::chrono::high_resolution_clock::now();

#if 0
    alarm(0);
    refresh(0);
    unsigned long ttsteps = steps;
    unsigned long ttclocks = clocks;

    if (ttclocks < tclocks) {
        ttclocks += step*CLOCKS_PER_SEC;
        ttsteps--;
    }
    res += (ttsteps - tsteps)*step*100 + (ttclocks - tclocks)/(CLOCKS_PER_SEC/100);
#endif
}

void
Timer::print() {
#if 0
    unsigned long t = res, hours, mins, secs;

    hours = t / hour;
    t -= hours * hour;

    mins = t / min;
    t -= mins * min;

    secs = t / sec;
    t -= secs * sec;
#endif

    std::cout << *this << std::endl;
}


std::ostream &operator<<(std::ostream &out, const Timer &value) {
    boost::chrono::high_resolution_clock::duration t = value.end - value.begin;

    boost::chrono::hours hours = boost::chrono::duration_cast< boost::chrono::hours> (t);
    t -= hours;

    boost::chrono::minutes mins = boost::chrono::duration_cast< boost::chrono::minutes > (t);
    t -= mins ;

    boost::chrono::seconds secs = boost::chrono::duration_cast< boost::chrono::seconds > (t);
    t -= secs;

    boost::chrono::microseconds  msecs = boost::chrono::duration_cast< boost::chrono::microseconds > (t);

    out << std::setw(2) << std::setfill('0') << hours.count() << ":" <<
        std::setw(2) << std::setfill('0') << mins.count() << ":" <<
        std::setw(2) << std::setfill('0') << secs.count() << "." <<
        std::setw(2) << std::setfill('0') << msecs.count();

    return out;
}
