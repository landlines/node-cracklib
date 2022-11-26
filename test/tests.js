var assert = require('assert');
var cracklib = require('../build/Release/cracklib');

const nonMatch = 'should have a null message for a non-matching password';
const match = 'should have a warning message for a matching password';
describe('cracklib', function () {
    describe('#fascistCheck()', function () {
        it(nonMatch, function () {
            assert.equal(cracklib.fascistCheck('Y0urPa55word').message, null);
        });
        it(match, function () {
            assert.equal(cracklib.fascistCheck('Pa55word').message, 
                'it is based on a dictionary word');
        });
    });

    describe('#fascistCheckUser()', function () {
        it(nonMatch, function () {
            assert.equal(cracklib.fascistCheckUser('Y0urPa55word', 
                'dan').message, null);
        });
        it(match, function () {
            assert.equal(cracklib.fascistCheckUser('Pa55word',
                'dan').message, 'it is based on a dictionary word');
        });
    });
});
