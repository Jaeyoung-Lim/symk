#ifndef OPEN_LISTS_OPEN_LIST_BUCKETS_H
#define OPEN_LISTS_OPEN_LIST_BUCKETS_H

#include "open_list.h"
#include "../scalar_evaluator.h"

#include <deque>
#include <utility>
#include <vector>

template<class Entry>
class BucketOpenList : public OpenList<Entry> {
    typedef std::deque<Entry> Bucket;
    std::vector<Bucket> buckets;
    mutable int lowest_bucket;
    int size;

    ScalarEvaluator *evaluator;
    int last_evaluated_value;
    bool last_preferred;
    bool dead_end;
    bool dead_end_reliable;

protected:
    ScalarEvaluator* get_evaluator() { return evaluator; }

public:
    BucketOpenList(ScalarEvaluator *eval, bool preferred_only);
    ~BucketOpenList();
    
    int insert(const Entry &entry);
    Entry remove_min();
    bool empty() const;
    void clear();
    
    void evaluate(int g, bool preferred);
    bool is_dead_end() const;
    bool dead_end_is_reliable() const;
    void get_involved_heuristics(std::set<Heuristic*> &hset);
    
    static OpenList<Entry> *create(const std::vector<std::string> &config, 
                                   int start, int &end);
};

#include "open_list_buckets.cc"

// HACK! Need a better strategy of dealing with templates, also in the Makefile.

#endif
