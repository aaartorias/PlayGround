package main.java.cache;

import java.util.Hashtable;

public class L1Cache extends Cache{
    private Hashtable<String, String> table;
    private L1Cache nextCache = null;

    public L1Cache() {}

    public L1Cache(L1Cache nextCache) {
        this.nextCache = nextCache;
    }

}
