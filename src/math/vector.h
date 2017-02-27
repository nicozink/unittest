/*
Copyright © 2016, Nico Zink
All rights reserved.
*/

#ifndef VECTOR_H
#define VECTOR_H

// Local Includes

// Project Includes

// External Includes
#include <cstdarg>
#include <initializer_list>

// Referenced classes.

// Stores a vector of the specified type and dimensions.
// @type TType The type of the object stored in the vector.
// @type TSize The size of the vector.
template <typename TType, int TSize>
class Vector
{
  public:
    
    //
    // Constructors
    //
    
    // Creates a new instance of the Vector class.
    Vector()
    {
      
    }

    // Creates a new instance of the Vector class.
    // @param values The values.
    Vector(TType values[TSize])
    {
      for (int i = 0; i < TSize; ++i)
      {
        this->values[i] = values[i];
      }
    }
    
    // Creates a new instance of the Vector class.
    // @param list The list of arguments.
    Vector(std::initializer_list<TType> list)
    {
      int c = 0;
      
      for(auto elem : list)
      {
        this->values[c] = elem;
        
        ++c;
      }
    }
    
    // Destroys this instance of the Vector class.
    virtual ~Vector()
    {
    
    }
    
    //
    // Operators
    //
    
    // Returns the value stored in the given index.
    // @param i The index.
    // @returns The value.
    TType& operator () (int i)
    {
      return values[i];
    }
    
    // Returns the value stored in the given index.
    // @param i The index.
    // @returns The value.
    TType* operator * ()
    {
      return values;
    }
    
    //
    // Public Methods
    //
    
    // Returns the value stored in the given index.
    // @param i The index.
    // @returns The value.
    TType& Get(int i)
    {
      return values[i];
    }
    
    // Returns the value stored in the given index.
    // @param i The index.
    // @returns The value.
    TType Get(int i) const
    {
      return values[i];
    }

    // Gets the values stored in the array.
    // @returns The values.
    TType* GetArray()
    {
      return values;
    }

  protected:
  
    //
    // Protected Variables
    //
    
    // Contains the values stored in the vector.
    TType values[TSize];
};

#endif