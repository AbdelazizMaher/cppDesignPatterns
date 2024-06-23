# Creational Design Patterns

Creational design patterns are a category of design patterns that deal with object creation mechanisms. These patterns provide various object creation mechanisms, which increase flexibility and reuse of existing code.

## What Are Creational Design Patterns?

Creational design patterns abstract the instantiation process. They help make a system independent of how its objects are created, composed, and represented. Creational patterns give a program more flexibility in deciding which objects need to be created for a given use case.

### Key Benefits

1. **`Flexibility and Reusability`**: Creational patterns offer ways to encapsulate the instantiation process
2. **`Decoupling Code`**: By abstracting the instantiation process, these patterns help to decouple your code from specific implementations
3. **`Object Management`**: These patterns provide mechanisms to manage and control how objects are created

## Types of Creational Design Patterns

### 1. Singleton

The Singleton pattern ensures that a class has only one instance and provides a global point of access to it.

#### **`Intent`**

- Ensure a class has only one instance.
- Provide a global point of access to the instance.

#### **`Motivation`**

Useful when exactly one object is needed to coordinate actions across a system. For example, a configuration manager or a logging class.


### 2. Factory Method

The Factory Method pattern defines an interface for creating an object, but lets subclasses alter the type of objects that will be created.

#### **`Intent`**

- Define an interface for creating an object, but let subclasses decide which class to instantiate.
- Factory Method lets a class defer instantiation to subclasses.

#### **`Motivation`**

Useful for scenarios where a class cannot anticipate the class of objects it must create or when a class wants its subclasses to specify the objects it creates.

### 3. Abstract Factory

The Abstract Factory pattern provides an interface for creating families of related or dependent objects without specifying their concrete classes.

#### **`Intent`**

- Provide an interface for creating families of related or dependent objects without specifying their concrete classes.

#### **`Motivation`**

Useful when a system should be independent of how its products are created, composed, and represented or when a system should be configured with one of multiple families of products.

### 4. Builder

The Builder pattern separates the construction of a complex object from its representation so that the same construction process can create different representations.

#### **`Intent`**

- Separate the construction of a complex object from its representation.
- Allow the same construction process to create different representations.

#### **`Motivation`**

Useful when the construction process of a product must allow different representations.

### 5. Prototype

The Prototype pattern creates new objects by copying an existing object, known as the prototype.

#### **`Intent`**

- Specify the kinds of objects to create using a prototypical instance.
- Create new objects by copying this prototype.

#### **`Motivation`**

Useful when the types of objects to create are determined by instances that are copied.
