/*************************************************************************/
/*  array.h                                                              */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2019 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2019 Godot Engine contributors (cf. AUTHORS.md)    */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "core/typedefs.h"

class Variant;
class HeapPrivate;
class PrioritizedItem;

class PriorityQueue {

    mutable HeapPrivate *_p;
    void _ref(const PriorityQueue &p_from) const;
    void _unref() const;

public:
    Variant &operator[](int p_idx);
    const Variant &operator[](int p_idx) const;

    void insert(const Variant &p_value, float p_priority);
    void update(const Variant &p_value, float p_priority);

    int size() const;
    bool empty() const;
    void clear();

    Variant front() const;
    Variant back() const;



    Variant pop_back();
    Variant pop_front();

    PriorityQueue duplicate(bool p_deep = false) const;

    PriorityQueue(const PriorityQueue &p_from)
    PriorityQueue();
    ~PriorityQueue();
}


#endif // PRIORITY_QUEUE_H