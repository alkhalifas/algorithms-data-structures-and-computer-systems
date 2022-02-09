Why is a ring buffer useful and/or when should it be used?

Circular Queues, Circular Buffers, or Ring Buffers are are a type of data structure allowing us to implement a first-in-first-out ordering. In essence, we can think of ring buffers as a list or array in a circular fashion in which the maximum size or capacity of the instance is known. Similar to an array, a circular buffer maintains a particular order, as well as a head/tail (front/back) as we can see in the following diagram with the array represented on the left, and the circular buffer on the right.

![image of ciruclar buffer](https://github.com/Spring22DSAlgoSys/monorepo-alkhalifas/blob/main/Assignment3_Queues/part1/cs5008-circular-buffer.png?raw=true)

One main point about ring buffers is that this type of structure does not expact after being allocated to dynamic memory. In other words, this structure is of a fixed size. Given that it is if a fixed size, we can use this to our advantage when trying to wrap around the circular structure using the mod(%) operator. 

This type of structure has a few advantages in the sense that it allows us to conserve memory since we can only store data up to the capacity of the structure, does not need to be copied or reorganized in order to be modified, and from an efficiency (Big O) perspective, its operations occur at O(1). In essence, it is a very efficiency structure to use.

One of the main disadvantages about ring buffers is the fact that its size would need to be known ahead of time. Once the structure itself is dynamically allocated, it cannot be modified or changed. Ring buffers are a great solution for when the sizes are known, otherwise other options may be a better path.
