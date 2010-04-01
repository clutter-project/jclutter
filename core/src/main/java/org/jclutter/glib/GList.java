package org.jclutter.glib;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

public class GList<T extends GObject> implements List<T> {
	
	private int pointer;
	
	protected GList(int handle) {
		pointer = handle;
	}

	public native boolean add(T e);

	public void add(int index, T element){
		addAt(index, element);
	}
	
	private native void addAt(int index, T element);

	public boolean addAll(Collection<? extends T> c) {
		for(T e : c){
			add(e);
		}
		return false;
	}

	public boolean addAll(int index, Collection<? extends T> c) {
		// TODO reverse collection
		for(T e : c){
			add(index, e);
		}
		return false;
	}

	public native void clear();

	public boolean contains(Object o) {
		if (o instanceof GObject){
			for (T e : this){
				if (o.equals(e)) return true;
			}
		}
		return false;
	}

	public boolean containsAll(Collection<?> c) {
		boolean b = true;
		for(Object e : c){
			b = contains(e);
			if (!b) break;
		}
		return b;
	}

	public native T get(int index);

	@Override
	public int indexOf(Object o) {
		return -1;
	}
	
	public native int indexOf(T o);

	public boolean isEmpty() {
		return size() == 0;
	}

	public Iterator<T> iterator() {
		return listIterator();
	}

	public int lastIndexOf(Object o) {
		int i = -1;
		for (int j = 0; j < size(); j++) {
			if (get(j).equals(o)) i = j;
		}
		return i;
	}

	public ListIterator<T> listIterator() {
		return new GListIterator<T>(this.pointer);
	}

	public ListIterator<T> listIterator(int index) {
		if (index >= size()) return null;
		// temporary solution
		GListIterator<T> gl = new GListIterator<T>(this.pointer);
		for (int i = 0; i < index; i++) {
			gl.next();
		}
		return gl;
	}

	public boolean remove(Object o) {
		int index = indexOf(o);
		if (index >= 0)
		return (remove(index)!=null);
		else return false;
	}

	public native T remove(int index);

	public boolean removeAll(Collection<?> c) {
		int i = 0;
		for(Object o : c){
			if (remove(o)) i++;
		}
		return i > 0;
	}

	public boolean retainAll(Collection<?> c) {
		boolean b = false;
		for(Object o : this){
			if (!c.contains(o)){
				if (remove(o)) b = true;
			}
		}
		return b;
	}

	public native T set(int index, T element);

	public native int size();

	public List<T> subList(int fromIndex, int toIndex) {
		List<T> li = new ArrayList<T>();
		for (int i = fromIndex; i < toIndex + 1; i++) {
			li.add(get(i));
		}
		return li;
	}

	public Object[] toArray() {
		Object [] arr = new Object[size()];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = get(i);
		}
		return arr;
	}

	// do not use
	@SuppressWarnings("unchecked")
	public Object[] toArray(Object[] a) {
		Object [] arr = new Object[size()];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = get(i);
		}
		return arr;
	}
	
	@Override
	public int hashCode() {
		return pointer;
	}
	
	@Override
	public boolean equals(Object obj) {
		return obj.hashCode() == hashCode();
	}

}
