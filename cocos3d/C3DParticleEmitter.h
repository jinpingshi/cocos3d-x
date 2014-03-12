#ifndef PARTICLEEMITTER_H_
#define PARTICLEEMITTER_H_

#include "C3DTransform.h"
#include "C3DMesh.h"
#include "C3DVector2.h"
#include "C3DVector3.h"
#include "C3DVector4.h"
#include "C3DTexture.h"
#include "Rectangle.h"

#include "C3DElementNode.h"
#include "cocos2d.h"

namespace cocos3d
{
//class Node;
class C3DElementNode;
class C3DParticleSystem;

/**
  Defines a particle emitter that can be made to simulate a particle system.
  This emitter defines the emission rate, particle start size, end size, age,
  position, velocity, rotation and so on...
*/
class C3DParticleEmitter
{
    //friend class Node;

public:

	/**
	constructor & destructor
	*/
    C3DParticleEmitter(C3DParticleSystem* system);

    ~C3DParticleEmitter();

    /**
     * Creates a particle emitter from the specified properties object.
     *
     * @param properties The properties object defining the
     *      particle properties.
     */
    void load(C3DElementNode* properties);

	/**
     * Save particlesystem to properties object.
     *
     * @param properties The properties object.
     */
	void save(C3DElementNode* properties);
    /**
     * Sets the emission rate, measured in particles per second.
     *
     * @param rate The emission rate, measured in particles per second.
     */
    void setEmissionRate(unsigned int rate);

    /**
     * Gets the emission rate, measured in particles per second.
     *
     * @return The emission rate, measured in particles per second.
     */
    unsigned int getEmissionRate() const;

    /**
     * Generates an arbitrary number of particles all at once.  Each newly emitted
     * particle has its properties assigned within the ranges defined by its ParticleEmitter.
     *
     * Note that the maximum number of particles that can be alive at once in a particle
     * system is defined when a ParticleEmitter is created and cannot be changed.  A call
     * to emit() cannot cause the particle system to exceed this maximum, so fewer or zero
     * particles will be emitted if the maximum is or has been reached.
     *
     * @param particleCount The number of particles to emit immediately.
     */
    void emit(unsigned int particleCount);

    /**
     * Sets whether the positions of newly emitted particles are generated within an ellipsoidal domain.
     *
     * Each vector property is generated such as to fall within the domain defined by a base vector and a
     * variance vector. If that domain is ellipsoidal, vectors are generated within an ellipsoid centered
     * at the base vector and scaled by the variance vector. If that domain is not ellipsoidal, vectors are
     * generated by multiplying the variance vector by a random floating-point number between -1 and 1,
     * then adding this result to the base vector.
     *
     * Ellipsoidal domains are somewhat less efficient and only necessary when determining the positions of
     * newly emitted particles.  Call this method with 'true' to make initial position an ellipsoidal domain.
     * The default setting is 'false'.
     *
     * @param ellipsoid Whether initial particle positions are generated within an ellipsoidal domain.
     */
    void setEllipsoid(bool ellipsoid);

    /**
     * Determines whether the positions of newly emitted particles are generated within an ellipsoidal domain.
     *
     * @return true if is ellipsoid, false if not.
     */
    bool isEllipsoid() const{ return _ellipsoid; }

    /**
     * Sets the minimum and maximum size that each particle can be at the time when it is spawned,
     *
     * @param startMin The minimum size that each particle can be at the time when it is started.
     * @param startMax The maximum size that each particle can be at the time when it is started.
     */
    void setSize(float startMin, float startMax);

	/**
     * Sets the minimum size that each particle can be at the time when it is spawned,
     */
	void setSizeStartMin(float startMin);
	/**
     * Sets the maximum size that each particle can be at the time when it is spawned,
     */
	void setSizeStartMax(float startMax);

    /**
     * Gets the minimum size that each particle can be at the time when it is started.
     *
     * @return The minimum size that each particle can be at the time when it is started.
     */
    float getSizeStartMin() const;

    /**
     * Gets the maximum size that each particle can be at the time when it is started.
     *
     * @return The maximum size that each particle can be at the time when it is started.
     */
    float getSizeStartMax() const;

    /**
     * Sets the minimum and maximum lifetime of emitted particles, measured in milliseconds.
     *
     * @param energyMin The minimum lifetime of each particle, measured in milliseconds.
     * @param energyMax The maximum lifetime of each particle, measured in milliseconds.
     */
    void setAge(long ageMin, long ageMax);

	/**
     * Sets the minimum lifetime of emitted particles, measured in milliseconds.
     */
	void setAgeMin(long ageMin);
	/**
     * Sets the maximum lifetime of emitted particles, measured in milliseconds.
     */
	void setAgeMax(long ageMax);

    /**
     * Gets the minimum lifetime of each particle, measured in milliseconds.
     *
     * @return The minimum lifetime of each particle, measured in milliseconds.
     */
    long getAgeMin() const;

    /**
     * Gets the maximum lifetime of each particle, measured in milliseconds.
     *
     * @return The maximum lifetime of each particle, measured in milliseconds.
     */
    long getAgeMax() const;

    /**
     * Sets the initial position and position variance of new particles.
     *
     * @param position The initial position of new particles.
     * @param positionVariance The amount of variance allowed in the initial position of new particles.
     */
    void setPosition(const C3DVector3& position, const C3DVector3& positionVariance);

	/**
	 * Sets the initial position of new particles
	 */
	void setPosition(const C3DVector3& position);

	/**
	 * Sets the initial position variance of new particles
	 */
	void setPositionVariance(const C3DVector3& positionVariance);

    /**
     * Gets the position of new particles, relative to the emitter's transform.
     *
     * @return The position of new particles, relative to the emitter's transform.
     */
    const C3DVector3& getPosition() const;

    /**
     * Gets the position variance of new particles.
     *
     * @return The position variance of new particles.
     */
    const C3DVector3& getPositionVariance() const;

    /**
     * Sets the base velocity of new particles and its variance.
     *
     * @param velocity The initial velocity of new particles.
     * @param velocityVariance The amount of variance allowed in the initial velocity of new particles.
     */
    void setVelocity(const C3DVector3& velocity, const C3DVector3& velocityVariance);

	/**
	 * Sets particles velocity
	 */
	void setVelocity(const C3DVector3& velocity);

	/**
	 * Sets the particles velocity variance
	 */
	void setVelocityVariance(const C3DVector3& velocityVariance);

    /**
     * Gets the initial velocity of new particles.
     *
     * @return The initial velocity of new particles.
     */
    const C3DVector3& getVelocity() const;

    /**
     * Gets the initial velocity variance of new particles.
     *
     * @return The initial velocity variance of new particles.
     */
    const C3DVector3& getVelocityVariance() const;

    /**
     * Gets the maximum rotation speed of each emitted particle.
     * This determines the speed of rotation of each particle's screen-facing billboard.
     *
     * @param speedMin The minimum rotation speed (per particle).
     * @param speedMax The maximum rotation speed (per particle).
     */
    void setRotationPerParticle(float speedMin, float speedMax);

	/**
	 * Sets minimum rotation speed
	 */
	void setRotationPerParticleSpeedMin(float speedMin);

	/**
	 * Sets maximum rotation speed
	 */
	void setRotationPerParticleSpeedMax(float speedMax);

    /**
     * Gets the minimum rotation speed of each emitted particle.
     *
     * @return The minimum rotation speed of each emitted particle.
     */
    float getRotationPerParticleSpeedMin() const;

    /**
     * Gets the maximum rotation speed of each emitted particle.
     *
     * @return The maximum rotation speed of each emitted particle.
     */
    float getRotationPerParticleSpeedMax() const;

    /**
     * Sets a rotation axis in world space around which all particles will spin,
     * as well as the minimum and maximum rotation speed around this axis.
     * This should not be confused with rotation speed per particle.
     *
     * @param axis The base rotation axis of emitted particles.
     * @param axisVariance The variance of the rotation axis of emitted particles.
     * @param speedMin The minimum rotation speed of emitted particles.
     * @param speedMax The maximum rotation speed of emitted particles.
     */
   void setRotation(float speedMin, float speedMax, const C3DVector3& axis, const C3DVector3& axisVariance);

   /**
	 * Sets rotation axis
	 */
   void setRotationAxis(const C3DVector3& axis);

   /**
	 * Sets rotation axis variance
	 */
   void setRotationAxisVariance(const C3DVector3& variance);

    /**
     * Gets the minimum rotation speed of emitted particles.
     *
     * @return The minimum rotation speed of emitted particles.
     */
    float getRotationSpeedMin() const;

	/**
	 * Sets rotation minimum speed
	 */
	void setRotationSpeedMin(float speedmin)
	{
		_rotationSpeedMin = speedmin;
	}

    /**
     * Gets the maximum rotation speed of emitted particles.
     *
     * @return The maximum rotation speed of emitted particles.
     */
    float getRotationSpeedMax() const;

	/**
	 * Sets maximum rotation speed
	 */
	void setRotationSpeedMax(float speedMax)
	{
		_rotationSpeedMax = speedMax;
	}

    /**
     * Gets the base rotation axis of emitted particles.
     *
     * @return The base rotation axis of emitted particles.
     */
    const C3DVector3& getRotationAxis() const;

    /**
     * Gets the variance of the rotation axis of emitted particles.
     *
     * @return The variance of the rotation axis of emitted particles.
     */
    const C3DVector3& getRotationAxisVariance() const;

    /**
     * Sets whether the vector properties of newly emitted particles are rotated around the node's position
     * by the node's rotation matrix.
     *
     * @param orbitPosition Whether to rotate initial particle positions by the node's rotation matrix.
     * @param orbitVelocity Whether to rotate initial particle velocity vectors by the node's rotation matrix.
     * @param orbitAcceleration Whether to rotate initial particle acceleration vectors by the node's rotation matrix.
     */
    void setOrbit(bool orbitPosition, bool orbitVelocity, bool orbitAcceleration);

	/**
	 * Sets whether the vector properties of newly emitted particles are rotated around the node's position
	 */
	void setOrbitPosition(bool orbitPos) { _orbitPosition = orbitPos; }
	/**
	 * whether the vector properties of newly emitted particles are rotated around the node's position
	 */
	bool isOrbitPosition() const { return _orbitPosition; }

	/**
	 * set & get Whether to rotate initial particle velocity vectors by the node's rotation matrix.
	 */
	void setOrbitVelocity(bool orbitVel) { _orbitVelocity = orbitVel; }
	bool isOrbitVelocity() const { return _orbitVelocity; }

	/**
	 * set & get Whether to rotate initial particle acceleration vectors by the node's rotation matrix.
	 */
	void setOrbitAcceleration(bool acceleration) { _orbitAcceleration = acceleration; }
	bool isOrbitAcceleration() const { return _orbitAcceleration; }

	void setEmitStart(bool bStart) { _started = bStart; }
	bool isEmitStart() { return _started; }

    /**
     * Updates the particles currently being emitted.
     *
     * @param elapsedTime The amount of time that has passed since the last call to update(), in milliseconds.
     */
    void update(long elapsedTime);

    /**
     * Draws the particles currently being emitted.
     */
    void draw();

	/**
     * clone method.
     */
    C3DParticleEmitter* clone(C3DParticleSystem* system) const;

private:

    /**
     * Generates a scalar within the range defined by min and max.
     */
    float generateScalar(float min, float max);
    long generateScalar(long min, long max);

    /**
     * Generates a vector within the domain defined by a base vector and its variance.
     */
    void generateVectorInRect(const C3DVector3& base, const C3DVector3& variance, C3DVector3* dst);

    /**
     * Generates a vector within the ellipsoidal domain defined by a center point and scale vector.
     */
    void generateVectorInEllipsoid(const C3DVector3& center, const C3DVector3& scale, C3DVector3* dst);
    void generateVector(const C3DVector3& base, const C3DVector3& variance, C3DVector3* dst, bool ellipsoid);

    //particle emitter properties
    unsigned int _emissionRate;
    bool _started;
    bool _ellipsoid;
    float _sizeStartMin;
    float _sizeStartMax;
    float _ageMin;
    float _ageMax;

    C3DVector3 _position;
    C3DVector3 _positionVar;
    C3DVector3 _velocity;
    C3DVector3 _velocityVar;

    float _rotationPerParticleSpeedMin;
    float _rotationPerParticleSpeedMax;
    float _rotationSpeedMin;
    float _rotationSpeedMax;
    C3DVector3 _rotationAxis;
    C3DVector3 _rotationAxisVar;
    C3DMatrix _rotation;

    bool _orbitPosition;
    bool _orbitVelocity;
    bool _orbitAcceleration;
    float _timePerEmission;
    long _timeLast;
    long _timeRunning;

	C3DParticleSystem* _system;
};
}

#endif
